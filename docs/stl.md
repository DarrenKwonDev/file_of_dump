

<!-- toc -->

- [STL(standard template library)](#stlstandard-template-library)
  * [STL container](#stl-container)
    + [vector. 동적 배열](#vector-%EB%8F%99%EC%A0%81-%EB%B0%B0%EC%97%B4)
    + [map](#map)
    + [set](#set)
    + [tuple](#tuple)
    + [unordered_map](#unordered_map)
    + [stack](#stack)
    + [queue](#queue)
    + [deque](#deque)
    + [priority_queue](#priority_queue)
    + [list(circular doubly linked list)](#listcircular-doubly-linked-list)

<!-- tocstop -->

# STL(standard template library)

## STL container

https://en.cppreference.com/w/cpp/container

map, set, vector 정도가 자주 쓰이는 편.

-   타 회사들이 자체적으로 제작한 STL 개선 버전
    -   [EA STL](https://github.com/electronicarts/EASTL)

### vector. 동적 배열

https://en.cppreference.com/w/cpp/container/vector

-   메모리 연속성
    vector 자료구조는 메모리 상 원소들이 연속된 공간에 존재.

-   reallocations
    이러한 자료 구조가 동적이기 위하여 원소 수가 한계 이상이 되면 메모리 공간을 전부 옮겨야 함.

-   capacity (cap)
    the total number of elements that the vector can hold without requiring reallocation

-   size
    실제로 존재하는 원소의 갯수. capacity를 넘어가는 순간 realloc 발생.

-   complexity
    배열과 같으므로 임의 원소 접근 O(1)  
    삽입 및 삭제에 대해서도 배열과 같이 이동 과정이 있으므로 O(N)  
    Random access - constant 𝓞(1).  
    Insertion or removal of elements at the end - amortized constant 𝓞(1).  
    Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n).

-   iterator, reverse_iterator

    begin/end 조합은 앞에서부터
    rbegin/rend 조합은 뒤에서부터 조회하기 위한 도구임.

    vector<T>.end()가 요소의 마지막이 아닌 `마지막 한 칸 뒤`을 가리킴에 주의.  
    마찬가지로 r.end()는 요소의 처음이 아닌 `맨 앞에서 한 칸 앞`을 가리킴.

    <img src="../imgs/range-rbegin-rend.svg" />

-   insert
    삽입된 값을 가리키는 반복자가 반환됨.

-   erase
    the end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for pos.

    -   return 값이 독특함
        -   지운 후 해당 위치를 가리키는 반복자를 반환함.
        -   예외: 마지막 원소를 지우는 경우, 마지막 원소를 가리키는 반복자가 아닌 v.end()를 반환함.

-   tips
    1. vector 생성하고 바로 reserve로 cap 잡아라. 쓸만큼 선언하고, 재할당이 일어나지 않도록 넉넉해야 한다.
    2. 객체를 직접 보관하는 벡터는 재할당 시에 재할당 및 원소 복사가 일어나는데 객체가 클수록 부하가 크다. 객체의 포인터를 지정하는 것이 경제적이다.
    3. 객체의 포인터를 저장하는 벡터의 원소가 사용하고 있는 heap 데이터를 정리하고 싶다면 수동으로 삭제해야 한다. vector.clear()는 원소를 삭제하지만 heap 데이터는 삭제하지 않는다. (114_stl_1/vector/ptr_vector_heap_cleanup.cpp 참고)

### map

https://en.cppreference.com/w/cpp/container/map

-   cpp맵의 특징  
    해시맵이 아니다.
    키 기준 자동 정렬이 됨. 정렬을 위해 내부적으로 binary search tree 사용.  
    키를 중복으로 삽입할 수 없다. 즉, 중복되는 키는 존재하지 않음.  
    만약 같은 키를 insert 시도하면 조용히 실패하며 반환 pair 중 second는 false를 가짐.

-   operator[]
    key 값이 있으면 덮어쓰기 되며, 없으면 가능한 경우 기본값으로 생성함. 기본값이 있는 경우 읽기 작업에서 operator[]를 쓰면 의도치 않은 값을 얻을 수도 있으니 주의.

    -   insert는 operator[]와 다르게 이미 키가 존재하면 무시한다.

-   object를 키로 가지는 맵
    해당 object가 operator<를 정의해야 함.

-   complexity
    std::map은 해시맵이 아님. 정렬 로직에 의하여 O(logN)이다.
    Search, removal, and insertion operations have logarithmic complexity

-   multi map
    -   중복 키 허용

### set

-   정렬되는 컨테이너
    std::map과 같이 binary search tree기반으로 오름차순 키 정렬이 이뤄짐.
    맵과 거의 같으며 complexity도 같음.

-   집합의 특성상 중복 원소가 존재하지 않음.

-   multi set
    -   중복키를 허용하는 set

### tuple

https://en.cppreference.com/w/cpp/utility/tuple

### unordered_map

-   해시맵

### stack

https://en.cppreference.com/w/cpp/container/stack

-   스택이 비어있는데 top, pop을 호출하면 런타임 에러
-   [a, b, c, ...] <- push
-   pop은 가장 뒤 (push 되는 쪽) 원소 제거. top은 최후방 원소 반환

### queue

https://en.cppreference.com/w/cpp/container/queue

-   큐가 비었는데 front나 back이나 pop을 호출하면 런타임 에러
-   front [a, b, c, ...] <- push back
-   pop은 가장 앞 (front) 원소 제거(즉, pop 메서드가 stack과 다르다. 그것이 queue니까...)

### deque

-   double ended queue
-   front [a, b, ...] back
-   vector와 deque와의 큰 차이점 : 연속의 유무.
    -   vector의 경우 공간이 부족하면, memory reallocate 과정을 거쳐야 하는데 deque의 경우 연속되지 않으니, 그냥 새로운 memory block 을 하나 할당하면 되니 평균적인 성능을 보장할 수 있음.

### priority_queue

https://en.cppreference.com/w/cpp/container/priority_queue

### list(circular doubly linked list)

https://en.cppreference.com/w/cpp/container/list

-   double linked list
    메모리 상 불연속적으로 존재. cache에 불리.

-   complexity
    삽입, 삭제에 O(1). 원소 탐색에 O(N)

-   erase
    -   the end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for pos.
-   ```cpp
        list<int> l = {1};
        list<int>::iterator i = l.end(); // i는 실제 데이터가 아닌 리스트의 끝을 나타내는 특별한 위치.
        // 실제 원소 3을 지우기 위하여 --i를 통해서 원소 3을 가리킴.
        // 그 결과 l.erase는 3을 지우게 되고 3의 다음 원소를 반환할 것으로 예상됨.
        // 그러나 3의 다음 원소는 없음.
        // 이 경우 문서를 읽어보면
        // If pos refers to the last element, then the end() iterator is returned.
        i = l.erase(--i);
        // 마지막 원소를 지운 경우 똑같이 마지막을 반환함.
        cout << *i << endl; // 2
    ```
