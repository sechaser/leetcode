#include <iostream>
#include <algorithm>
#include <vector>

//**********************************************Method 1**************************************************
//double findMedianSortedArray(std::vector<int>& nums1, std::vector<int>& nums2)
//{
//    for(std::vector<int>::size_type i = 0; i != nums2.size(); ++ i)
//        nums1.push_back(nums2[i]);

//    std::stable_sort(nums1.begin(), nums1.end());
//    double median;
//    size_t sz = nums1.size();
//    if(sz % 2 == 0)
//        median = (double)(nums1[sz/2-1] + nums1[sz/2])/2;
//    else
//        median = (double)(nums1[sz/2]);

//    return median;
//}


//*********************************************Method 2 **************************************************
//double findKth(int a[], int m, int b[], int n, int k)
//{
//    if(m > n)
//        return findKth(b, n, a, m, k);
//    if(m == 0)
//        return (double)b[k-1];
//    if(k == 1)
//    {
//        if(a[0] > b[0])
//            return (double)b[0];
//        else
//            return (double)a[0];
//    }

//    int pa, pb;
//    if(k/2 > m)
//        pa = m;       //"pa" is the index of after last element in array "a".
//    else
//        pa = k/2;     //"pa" is the index of median element in array "a".
//    pb = k - pa;

//    if(a[pa-1] < b[pb-1])
//        return findKth(a + pa, m - pa, b, n, k - pa);
//    else if(a[pa-1] > b[pb-1])
//        return findKth(a, m, b + pb, n - pb, k - pb);
//    else
//        return (double)a[pa-1];
//}


double findKth(int a[], int m, int b[], int n, int k)
{
    if(m ==0)
        return b[k-1];
    if(n == 0)
        return a[k-1];

    int i = m/2, j = n/2;

    if(a[i] <= b[j])
    {
        if(k > i + j + 1)
            return findKth(a+i+1, m-i-1, b, n, k-i-1);
        else
            return findKth(a, m, b, j, k);
    }
    else
    {
        if(k > i + j + 1)
            return findKth(a, m, b+j+1, n-j-1, k-j-1);
        else
            return findKth(a, i, b, n, k);
    }
}


double findMedianSortedArrays(int a[], int m, int b[], int n)
{
    int total = m + n;
    if(total & 0x01)
        return findKth(a, m, b, n, total/2 + 1);
    else
        return (double)(findKth(a, m, b, n, total/2) + findKth(a, m, b, n, total/2 + 1))/2;
}

int main()
{
    int a[] = {0, 6};
    int b[] = {1, 2, 3, 4, 5, 6, 7};

    double median = findMedianSortedArrays(a, 2, b, 9);
    std::cout<<median<<std::endl;

    system("pause");
    return 0;
}

