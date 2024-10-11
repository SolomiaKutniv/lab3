#include <iostream>
#include <vector>

using namespace std;

class RealNumbers
{
private:
    vector<double> numbers; 

public:

    RealNumbers(const vector<double>& nums) : numbers(nums) {}

    void add(double num) 
    {
        numbers.push_back(num);
    }

    double Maxnumber() const  //Пошук найбільшого числа
    {
        return *max_element(numbers.begin(), numbers.end());
    }

    double Minnumber() const //Пошук найменшого числа
    {
        return *min_element(numbers.begin(), numbers.end());
    }

    RealNumbers operator+(const RealNumbers& other) const 
    {
        vector<double> result;
        for (double num1 : numbers)
        {
            for (double num2 : other.numbers)
            {
                result.push_back(num1 + num2);
            }
        }
        return RealNumbers(result);
    }

    RealNumbers operator-(const RealNumbers& other) const 
    {
        vector<double> result;
        for (double num1 : numbers)
        {
            for (double num2 : other.numbers)
            {
                result.push_back(num1 - num2);
            }
        }
        return RealNumbers(result);
    }

    RealNumbers operator*(const RealNumbers& other) const
    {
        vector<double> result;
        for (double num1 : numbers) 
        {
            for (double num2 : other.numbers) 
            {
                result.push_back(num1 * num2);
            }
        }
        return RealNumbers(result);
    }

    RealNumbers operator/(const RealNumbers& other) const 
    {
        vector<double> result;
        for (double num1 : numbers) 
        {
            for (double num2 : other.numbers) 
            {
                if (num2 == 0) 
                {
                    cout<<("Помилка. Ділення на нуль");
                }
                result.push_back(num1 / num2);
            }
        }
        return RealNumbers(result);
    }

    void print() const 
    {
        for (double num : numbers) 
        {
            cout << num << " ";
        }
        cout << endl;
    }

    ~RealNumbers() {}
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    RealNumbers nums1({ 1.5, 2.4, 5.6, 3.7 });
    RealNumbers nums2({ 1.6, 0.5 });

    RealNumbers sum = nums1 + nums2;
    cout << "Сума чисел: ";
    sum.print();

    RealNumbers diff = nums1 - nums2;
    cout << "Різниця чисел: ";
    diff.print();

    RealNumbers product = nums1 * nums2;
    cout << "Добуток чисел: ";
    product.print();

    try 
    {
        RealNumbers fraction = nums1 / nums2;
        cout << "Частка чисел: ";
        fraction.print();
    }
    catch (const exception& e) 
    {
        cout << "Помилка: " << e.what() << endl;
    }

    try 
    {
        cout << "Найбільше число у першому масиві: " << nums1.Maxnumber() << endl;
        cout << "Найменше число у першому масиві: " << nums1.Minnumber() << endl;
    }
    catch (const exception& e) 
    {
        cout << "Помилка: " << e.what() << endl;
    }

    try
    {
        cout << "Найбільше число у другому масиві: " << nums2.Maxnumber() << endl;
        cout << "Найменше число у другому масиві: " << nums2.Minnumber() << endl;
    }
    catch (const exception& e)
    {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}

