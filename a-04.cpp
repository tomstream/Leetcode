#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int>::iterator Iterator;

double findKth(int* nums1, int n1, int* nums2, int n2, int k){
    cout << n1 <<" "<<n2<< " " << k ;
    if(n1 > n2)
        return findKth(nums2, n2, nums1, n1, k);
    if(n1 == 0)
        return nums2[k - 1];
    if(k == 1)
        return min(nums1[0], nums2[0]);
    if(n1 == 1){
        if(n2 == 1)
            return max(nums1[0], nums2[0]);
        if(nums2[k - 1]<= nums1[0])
            return nums2[k-1];
        else if(nums1[0] <= nums2[k - 1] && nums2[0] >= nums2[k-2] )
            return nums1[0];
        else return nums2[k-2];
    }
    int p1 = min(k/2, n1), p2 = k - p1;
    cout << " " << p1 << " " <<p2 <<endl;
    if(nums1[p1 - 1] < nums2[p2 - 1]){
        return findKth(nums1 + p1, n1 - p1, nums2, n2 - p1, k - p1);
    }else if(nums1[p1 - 1] > nums2[p2 -1]){
        return findKth(nums1, n1 - p2, nums2 + p2, n2 - p2, k - p2);
    }else{
        return nums1[p1 - 1];
    }
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int sum = nums1Size + nums2Size;
    if(sum & 0x1){
        return findKth(nums1, nums1Size, nums2, nums2Size,(sum+1)/2);
    }else{
        return 1.0*(findKth(nums1, nums1Size, nums2, nums2Size, sum / 2)
            + findKth(nums1, nums1Size, nums2, nums2Size, sum / 2 + 1))/2;
    }
}
int main(){
    int a[]={1,2};
    int b[]={1,2};
    cout << findMedianSortedArrays(b, 2, a, 2);
    return 0;
}
