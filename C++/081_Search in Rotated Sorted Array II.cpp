class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n == 0)
            return false;
        this->target = target;
        return searchIn(A, 0, n - 1);
    }
private:
    int target;
    bool searchIn(int *arr, int l, int r) {
        if (l > r)
            return false;
        if (l + 1 >= r)
            return arr[l] == target || arr[r] == target;
        int mid = l + ((r - l) >> 1);
        if (arr[mid] == target)
            return true;
        if (arr[r] > arr[l]) {
            if (arr[mid] < target)
                return searchIn(arr, mid + 1, r);
            else
                return searchIn(arr, l, mid - 1);
        }
        else if (arr[r] < arr[l]) {
            if (arr[mid] >= arr[l]) {
                if (target >= arr[l] && target <= arr[mid])
                    return searchIn(arr, l, mid - 1);
                else
                    return searchIn(arr, mid + 1, r);
            }
            else {
                if (target >= arr[mid] && target <= arr[r])
                    return searchIn(arr, mid + 1, r);
                else
                    return searchIn(arr, l, mid - 1);
            }
        }
        else {
            if (arr[l] == target)
                return true;
            return searchIn(arr, l + 1, r - 1);
        }
    }
};