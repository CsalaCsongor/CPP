#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <random>
using namespace std;

int main() {
    vector<string> fruits {
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };
//---------------------1-------------------
    bool vanBerry = find_if(fruits.begin(), fruits.end(), [](const string& fruit){
        return fruit.find("berry") != string::npos;
    }) != fruits.end();

    cout << "van berry " << vanBerry << endl;

//---------------------2-------------------
    vector<int> numbers{0, 2, 6, 4};
    bool parosElemek = all_of(numbers.begin(), numbers.end(), [](const int num){
        return num%2==0;
    });
    cout << "Parosak az elemek:" << parosElemek << endl;


    //---------------------3-------------------

    for_each(numbers.begin(), numbers.end(), [](int& num){
        num*=2;
    });
    for(int i :numbers)
    {
cout<< i << " ";
    }
    cout<<endl;

    //---------------------4-------------------
    vector<string> months {
            "january", "february", "march", "april", "may", "june",
            "July", "August", "September", "October", "November", "December"
    };
    int count=0;
    for_each(months.begin(), months.end(), [&count](const string& month){
        if(month.size()==5)
            count++;
    });

    auto count2 = count_if(months.begin(), months.end(), [](const string& month){
        return month.length() == 5;
    });

    cout<< "5 karakteres szavak: "<<count<< " " << count2<<endl;

    //---------------------5-------------------

    sort(numbers.begin(), numbers.end(), [](int a, int b){
        return a>b;
    });
    for(int i :numbers){cout<< i << " ";}cout<<endl;

    sort(numbers.begin(), numbers.end(),greater<int>());

    //---------------------6-------------------

    vector<pair<string, double>> monthsAndTemperature= {{"januar", 1.2}, {"februar", 2.2}, {"marcius", 12}, {"majus", 14}};
    sort(monthsAndTemperature.begin(), monthsAndTemperature.end(), [](const auto& a, const auto& b){
       return a.second<b.second;
    });
    for(auto i:monthsAndTemperature){
        cout<< i.second << " ";
    }
    cout<<endl;

    //---------------------7-------------------

    vector<double> numbers2 = {-1,-3.2, 5.6, 9.33, -7.1};
    sort(numbers2.begin(), numbers2.end(), [](auto& num1, auto& num2){
        return abs(num1) < abs(num2);
    });
    for(auto i:numbers2){
        cout<< i << " ";
    }
    cout<<endl;
//---------------------8-------------------
    for_each(months.begin(), months.end(), [](string& month){
        month[0] = tolower(month[0]);
    });

    for(const string& i:months)
    {
        cout<<i<<" ";
    }

    //---------------------9-------------------

    class furcsABC{

    };

    vector<char> abc = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                        'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    random_device rd;
    mt19937 g(rd());
    shuffle(abc.begin(), abc.end(), g);

    char reverseABC[255] = {0};
    for (int i = 0; i < abc.size(); ++i) {
        reverseABC[abc[i]] = i;
    }
    sort(months.begin(), months.end(), [&reverseABC](const string& a, const string& b){
        return lexicographical_compare(a.begin(), a.end(),
                                       b.begin(), b.end(),
                                       [&reverseABC](char a, char b){
            return reverseABC[a] < reverseABC[b];
        });
    });

        for(auto i:months){
            cout<< i << " ";
    }
    cout << endl;
        
    return 0;
}
