#include <iostream>
using namespace std;
float calculatePrice(float totalMoney, int year);
main()
{
    int year;
    float totalMoney;
    float sum;

    cout << "ENTER INHERETED MONEY in the range of [1 to 1000000] = ";
    cin >> totalMoney;
    cout << "ENTER  YEAR in the range of [1801 to 1900] = ";
    cin >> year;
    int count = 0;
    float resultPrice;
    resultPrice = calculatePrice(totalMoney, year);
    if (resultPrice > 0)
    {
        cout << "Yes! He will live a carefree life and will have " << resultPrice << " dollars left." << endl;
    }
    if (resultPrice < 0)
    {
        resultPrice = -(resultPrice);
        cout << "No!He will need " << resultPrice << " dollars to survive." << endl;
    }
}
float calculatePrice(float totalMoney, int year)
{
    int age = 18;
    for (int i = 1800; i <= year; i++)
    {
        if (i % 2 != 0)
        {
            totalMoney = totalMoney - (12000.00 + 50.00 * (age));
        }
        else if (i % 2 == 0)
        {
            totalMoney = totalMoney - 12000.00;
        }
        age = age + 1;
    }
    return totalMoney;
}