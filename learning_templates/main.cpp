#include <bits/stdc++.h>
using namespace std;
template <typename T>
void compareAndSwap(T &a, T &b, bool (*fptr)(T, T))
{
    if (fptr(a, b))
        swap(a, b);
}

template <typename T>
bool cmp(T a, T b)
{
    return a < b;
}

template <typename T, typename U>
bool cmp(pair<T, U> a, pair<T, U> b)
{
    return a.first < b.first;
}

template <typename T>
void sortArray(T *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

template <>
void sortArray<char *>(char *array[], int size)
{
    cout << "dsasdasd\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(array[i], array[j]) > 0)
            {
                swap(array[i], array[j]);
            }
        }
    }
}

template <typename T>
class Collection
{
    vector<T> v;

public:
    void add(T x)
    {
        v.push_back(x);
    }
    T max(bool (*fptr)(T, T))
    {
        T mx = v.back();
        for (auto it : v)
        {
            if (fptr(mx, it))
                mx = it;
        }
        return mx;
    }
};

template <>
bool cmp<string>(string a, string b)
{
    return a.size() < b.size();
}

template <typename T>
class Matrix
{
    int x, y;
    T **arr;

public:
    Matrix(int x, int y) : x(x), y(y)
    {
        arr = new T *[x];
        for (int i = 0; i < x; i++)
        {
            arr[i] = new T[y];
        }
    }

    void set(int i, int j, T x)
    {
        arr[i][j] = x;
    }
    T get(int i, int j)
    {
        return arr[i][j];
    }

    ~Matrix()
    {
        for (int i = 0; i < x; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

template <typename T>
class Matrix<T *>
{
    int x;
    vector<T> v;

public:
    Matrix(int x) : x(x)
    {
        v = vector<T>(x);
    }
    void set(int i, int j, T x)
    {
        v[i] = x;
    }
    T get(int i, int j)
    {
        return v[i];
    }
};

int main()
{
    int a = 1, b = 2;
    compareAndSwap(a, b, cmp);
    cout << a << ' ' << b << endl;

    double c = 1.2, d = 2.3;
    compareAndSwap(c, d, cmp);
    cout << c << ' ' << d << endl;

    pair<int, double> e = {1, 2}, f = {2, 3};
    compareAndSwap(e, f, cmp);
    cout << e.first << ' ' << f.first << endl;

    int arr[] = {5, 2, 9, 1, 5, 6};
    sortArray(arr, 6);

    for (auto it : arr)
        cout << it << ' ';
    cout << endl;

    const char *strArr[] = {"apple", "banana", "data", "cherry"};
    sortArray(strArr, 4);
    for (auto it : strArr)
        cout << it << ' ';
    cout << endl;

    Collection<int> intCol;
    intCol.add(1);
    intCol.add(44);
    intCol.add(22);

    cout << intCol.max(cmp) << endl;

    Collection<string> strCol;
    strCol.add("apple");
    strCol.add("bpplesad");
    strCol.add("cpplesdasd");
    strCol.add("dppldassdasde");
    strCol.add("apple");
    cout << strCol.max(cmp) << endl;

    Matrix<int> mat(3, 4);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat.set(i, j, i * 3 + j);
            cout << mat.get(i, j) << ' ';
        }
        cout << endl;
    }
    Matrix<int *> mat2(5);
    for (int i = 0; i < 5; i++)
    {
        mat2.set(i, i, i);
        cout << mat2.get(i, i) << ' ';
    }
}