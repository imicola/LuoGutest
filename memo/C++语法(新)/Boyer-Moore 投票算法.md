#模拟 #模板 
# Boyer-Moore 投票算法
  > 背景：数组中占比超过一半的元素称之为主要元素。给你一个 **整数** 数组，找出其中的主要元素，若不存在，输出 -1

- 一般我们习惯想到的方法是利用unordered_map 来存储每个数出现的次数，当发现有数字超过一半的时候，输出该数字，没有则在最后输出 -1

- **上述方法时间复杂度和空间复杂度均为 $O(n)$ ,而接下来介绍的算法，可以让空间复杂度降低到 $O(1)$**
- **Boyer-Moore 投票算法的基本思想是：在每一轮投票过程中，从数组中删除两个不同的元素，直到投票过程无法继续，此时数组为空或者数组中剩下的元素都相等**
  - 如果数组为空，则数组不存在主要元素
  - 如果数组剩下元素，则该元素可能为主要元素

**主要步骤：**

1. 维护一个候选主要元素 *candidate* 和该元素出现次数 *count* ,初始时 *candidate* 可以为任意值，*count =* 0
2.  遍历数组 *nums* 的所有元素，遍历到元素 $a_i$ 时进行如下操作：
   1. 如果 *count = 0* ,则将 $a_i$ 的值赋给 *candidate* ；否则不更新 *candidate* 的值
   2. 如果 $candidate = a_i$ ，则将 *count++*.否则 *count- -*

3. 遍历结束后,如果存在主要元素，则为 *candidate* ,否则其可以为数组中的任意元素

> [!tip]
>
> 在 ***Boyer-Moore*** 投票算法中，遇到相同的数则将 *count* 加 1，遇到不同的数则将 *count* 减 1
>
> 根据主要元素的定义，主要元素的出现次数大于其他元素的出现次数之和，因此在遍历过程中，主要元素和其他元素两两抵消，最后一定剩下至少一个主要元素，此时 *candidate* 为主要元素，且 $count \geq 1$

```cpp
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    int candidate = 0, counts = 0;
    for (auto &&i : nums) {
        cin >> i;
        if (counts == 0) candidate = i;
        if (candidate == i)
            counts++;
        else
            counts--;
    }
    int res = 0;
    for (auto &&i : nums) {
        if (i == candidate) {
            res++;
        }
    }
    cout << (res > nums.size() / 2 ? candidate : -1);
    return 0;
}
```