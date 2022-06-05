#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol128;
using namespace std;

/*takeaways
  - To achieve O(n), we need to use a hash table to store the length of
    a consecutive subsequence at the bounds
  - [1,2,4,5,3]
    - scan in 1, nothing exists in the hash table yet so map[1] = 1
      this means the subsequnce ends or starts with 1 has a length
      of 1
    - scan in 2, 1 is on its left, so left = map[1] = 1. nothing on
      2's right, so right = 0, so the total length of adding 2 in
      is left + right + 1 = 2 representing the subsequence "12".
      We have to update map[1]=map[2]=2
    - scan in 4 and 5. We now have map[4] = map[5] = 2 for the same reason
    - scan in 3.
      - map[3-1] = 2 means the subsequence ends at 2 has a length of 2
      - map[3+1] = 2 means the subsequence starts at 4 has a length of 2
      - the total length is now 2 + 1 + 2 = 5
      - we have to update the bounds. So map[3-left] = 5 and map[3+right] = 5
      - so map[1] = map[5] = 5

*/

int Solution::longestConsecutive(vector<int> &nums)
{
  auto m = unordered_map<int, int>();

  for (auto n : nums)
  {
    auto left = m.find(n - 1), right = m.find(n + 1);
    auto l = left != m.end() ? left->second : 0;
    auto r = right != m.end() ? right->second : 0;
    /* one is contributed by adding the number n */
    auto t = l + r + 1;
    /* update the bounds */
    m[n - l] = m[n + r] = t;
  }

  auto maxLen = 0;
  for (auto &[_, len] : m)
    maxLen = max(len, maxLen);

  return maxLen;
}