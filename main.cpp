#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol128;

/*
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
Therefore its length is 4.
*/

tuple<vector<int>, int>
testFixture1()
{
  auto input = vector<int>{100, 4, 200, 1, 3, 2};

  return make_tuple(input, 4);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;

  cout << "Expect to see : " << get<1>(f) << endl;
  cout << sol.longestConsecutive(get<0>(f)) << endl;
}

main()
{
  test1();
  return 0;
}