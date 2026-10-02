#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int find_first(const vector<int>& nums, int target)
{
    int left= 0 ;
    int right= nums.size() - 1 ;

    int answer=-1 ;

    while (left<=right) {

        int middle=left+ (right -left)/ 2 ;

        if (nums[middle] ==target)
        {

            answer =middle ;

            right=middle -1 ;

        } else if (nums[middle] <target)
        {

            left = middle + 1;

        } else
        {
            right = middle - 1;
        }
    }

    return answer ;
}

int find_last(const vector<int>& nums, int target)
{

    int left = 0;
    int right = nums.size() -1 ;

    int answer= -1 ;

    while (left<=right)
    {
        int middle=left+(right-left)/2;

        if (nums[middle] == target)
        {
            answer = middle ;

            left=middle + 1 ;

        } else if (nums[middle] < target)
        {
            left = middle + 1 ;

        } else
        {
            right = middle -1 ;
        }
    }

    return answer ;
}

pair<int, int> search_range(
    const vector<int>& nums,
    int target
)
{
    int first=find_first(nums, target) ;
    int last=find_last(nums, target) ;

    return {first, last} ;
}

int main()
{
    vector<int> nums1 =
    {
        5, 7, 7, 8, 8, 8, 10
    };

    pair<int, int> result1 =
        search_range(nums1, 8) ;

    cout << "Test 1: ";
    cout << "("
         << result1.first
         << ", "
         << result1.second
         << ")" << endl ;

    vector<int> nums2=
    {
        1, 2, 3, 4, 5
    };

    pair<int, int> result2 =
        search_range(nums2, 8) ;

    cout << "Test 2: " ;
    cout << "("
         << result2.first
         << ", "
         << result2.second
         << ")" << endl ;

    vector<int> nums3 =
    {
        1, 2, 3, 4, 5
    };

    pair<int, int> result3 =
        search_range(nums3, 3) ;

    cout <<"Test 3: ";
    cout << "("
         << result3.first
         << ", "
         << result3.second
         << ")" << endl ;

    return 0 ;
}