#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

static std::mutex sQueueLock;
static std::condition_variable sEvent;
static std::queue<int> sQueue;

void Consume() {
    while (true) {
        int val;
        {
            std::unique_lock<mutex> lock(sQueueLock);
            // FIXME: 만약, notify가 호출되지 않거나, wait가 notify보다 먼저 호출되면 영원히 기다림
            // https://en.cppreference.com/w/cpp/thread/condition_variable/wait
            sEvent.wait(lock, []() {
                // return이 true 라면 (sQueue에 뭔가 있다면) 깨어나라. (wait를 깨울 조건)
                // return이 false 라면 (sQueue가 비었다면) wait를 해라. (wait를 유지할 조건)
                // 결국, sQueue가 비어 있으면 다시 wait하라는 것.
                // 이런 확인 함수가 wait에 존재하는 이유는, notify를 안 했는데도 깨어나는 OS가 있어서...
                return !sQueue.empty();
            }); // lock을 풀고 sEvent.notify를 기다림.

            // 여기를 통과 했다는 건 누군가 notify해서 풀렸음을 의미
            val = sQueue.front();

            sQueue.pop();
        }
        cout << val << endl;
    }
}
void Produce() {
    std::unique_lock<mutex> lock(sQueueLock); // queue에 뭐 넣을거니까 lock걸고.

    sQueue.push(1);

    sEvent.notify_one(); // 다 넣었으니까 sEvent.wait 하고 있는 thread 깨우기
}

int main() {

    std::thread consumer(Consume);
    std::thread producer(Produce);

    consumer.join();
    producer.join();

    return 0;
}
