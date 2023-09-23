// quiz

{
    int nums[5] = {10, 20, 30, 40, 50}; /* nums[0]의 주소는 0x100 */
    int* ptr1 = nums + 2;               /* 30을 가리킴. 0x108 */
    int* ptr2 = &nums[0] + 2;           /* 30을 가리킴. 0x108 */

    return 0;
}

{
    int nums[5] = {10, 20, 30, 40, 50}; /* nums[0]의 주소는 0x100 */
    int* ptr1 = nums + 4;               /* 50을 가리킴. 0x110 */
    int* ptr2 = ptr1 - 2;               /* 30을 가리킴. 0x108 */

    return 0;
}

{
    int nums[5] = {10, 20, 30, 40, 50}; /* nums[0]의 주소는 0x100 */
    int* ptr1 = &nums[1] - 1;           /* 0x100 */
    int* ptr2 = ptr1 - 1;               /* 0x0fc */

    return 0;
}
