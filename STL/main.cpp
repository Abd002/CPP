#include <bits/stdc++.h>
using namespace std;

void dq(void)
{
    deque<char> first, second;

    string s;
    while (cin >> s)
    {
        if (s == "Insert")
        {
            char x;
            cin >> x;
            first.push_back(x);
        }
        else if (s == "Undo")
        {
            second.push_back(first.back());
            first.pop_back();
        }
        else if (s == "Redo")
        {
            first.push_back(second.back());
            second.pop_back();
        }
        else
            break;

        for (auto it : first)
        {
            cout << it;
        }
        cout << endl;
    }
}

void multiMap()
{
    string paragraph;
    getline(cin, paragraph);
    map<string, int> mp;
    stringstream stream(paragraph);
    string word;
    while (stream >> word)
    {
        mp[word]++;
    }
    multimap<int, string, greater<int>> mmap;
    for (auto it : mp)
    {
        mmap.insert({it.second, it.first});
    }

    for (auto it : mmap)
    {
        cout << it.second << ' ' << it.first << endl;
    }
}

void stack_()
{
    stack<string> st;

    string s;
    while (cin >> s)
    {
        if (s == "Open")
        {
            string x;
            cin >> x;
            st.push(x);
        }
        else if (s == "Close")
        {
            st.pop();
        }
        else if (s == "Current")
        {
            cout << st.top() << endl;
        }
        else
            break;
    }
}

void vec()
{
    vector<int> v = {3284, 231, 4357, 2332, 786};
    cout << accumulate(v.begin(), v.begin() + v.size(), 0) << endl;
    cout << *min_element(v.begin(), v.begin() + v.size()) << ' ' << *max_element(v.begin(), v.begin() + v.size()) << endl;
    sort(v.begin(), v.begin() + v.size(), greater<int>());
    for (auto it : v)
    {
        cout << it << ' ';
    }
    cout << endl;
}

void lst()
{
    list<int> list1 = {1, 2, 6, 12, 20};
    list<int> list2 = {3, 4, 5, 7, 8};
    list<int> ans;

    std::merge(list1.begin(), list1.end(), list2.begin(), list2.end(), std::back_inserter(ans));

    for (auto it : ans)
        cout << it << ' ';
    cout << endl;
}

class Person
{
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    Person() : name("sd"), age(0) {}

    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.age > p2.age; // Descending order by age
    }

    void print()
    {
        cout << name << ' ' << age << endl;
    }
    friend class CompareByAgeDescending;
};

class CompareByAgeDescending
{
public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.age < p2.age; // Descending order by age
    }
};

void testFunctors()
{
    vector<Person> ls = {Person("abd002", 12), Person("sadsad", 23), Person("gkjhk", 24)};
    sort(ls.begin(), ls.end(), Person());

    for (auto it : ls)
    {
        it.print();
    }
}

void predicate()
{
    list<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    v.remove_if([&](int x)
                { cout<<x<<endl;return (x % 2) == 1; });
    for (auto it : v)
        cout
            << it << ' ';
}

int main()
{
    // dq();
    // multiMap();
    // stack_();
    // vec();
    // lst();
    // testFunctors();
    predicate();
    return 0;
}