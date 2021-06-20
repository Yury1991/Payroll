#include <iostream>

#include "receiver.h"
#include "director.h"
#include "master.h"

using namespace std;

int main()
{


    Receiver receiver;
    Director director;
    Master master;

    double tempPrice = 0;
    int tempCalendarWorkingDays = 0;
    int tempWorkingDays = 0;
    //bool tempIsPremium;
    string temp;
    cout << "-----------------------------------Test Priemshika i directora---------------------------------------- :" << endl;
    cout << "Vvedite vyrabotku" << endl;
    cin >>tempPrice;
    receiver.setProfit(tempPrice);
    director.setProfit(tempPrice);

    cout << endl;

    cout << "Vvedite kolichesvo kalendarnyh rabochyh dnei:" << endl;
    cin >> tempCalendarWorkingDays;
    receiver.setCalendarWorkingDays(tempCalendarWorkingDays);
    director.setCalendarWorkingDays(tempCalendarWorkingDays);

    cout << endl;

    cout <<"Vvedite kolichestvo otrabottanyh dney:"<< endl;
    cin >> tempWorkingDays;
    receiver.setWorkingDays(tempWorkingDays);
    director.setWorkingDays(tempWorkingDays);

    cout << "Vyrabotka priemshika:" << endl;
    cout << receiver.calculateSalaryPercent() << endl;
    cout << "Vsego rabochyh calendarnyh dney:" << endl;
    cout << receiver.getCalendarWorkingDays() << endl;
    cout << "Otrabotannyh dney:" << endl;
    cout << receiver.getWorkingDays() << endl;
    cout <<"Oklad priemshika:" << endl;
    cout << (long int)receiver.calculateMinSalary() << endl;
    cout <<"Polnaya zarabotnaya plata priemshika:" << endl;
    cout << (long int)receiver.calculateTotalSalary() << endl;
    cout << endl;
    cout << "Vyrabotka directora:" << endl;
    cout << director.calculateSalaryPercent() << endl;
    cout << "Vsego rabochyh calendarnyh dney:" << endl;
    cout << director.getCalendarWorkingDays() << endl;
    cout << "Otrabotannyh dney:" << endl;
    cout << director.getWorkingDays() << endl;
    cout <<"Oklad directora:" << endl;
    cout << (long int)director.calculateMinSalary() << endl;
    cout <<"Doplata directora" << endl;
    cout << (long int)director.getDirectorFee() << endl;
    cout <<"Polnaya zarabotnaya plata directora:" << endl;
    cout << (long int)director.calculateTotalSalary() << endl;

/*    cout << "-----------------------------------Test Mastera---------------------------------------- :" << endl;
    cout << "Vvedite vyrabotku rabotnika" << endl;
    cin >>tempPrice;
    master.setMasterProfit(tempPrice);

    cout << endl;

    cout << "Vvedite kolichesvo kalendarnyh rabochyh dnei:" << endl;
    cin >> tempCalendarWorkingDays;
    master.setCalendarWorkingDays(tempCalendarWorkingDays);


    cout << endl;

    cout <<"Vvedite kolichestvo otrabottanyh dney:"<< endl;
    cin >> tempWorkingDays;
    master.setWorkingDays(tempWorkingDays);


    cout <<" Est li premiya? "<< endl;
    cin >> temp;
    if(temp == "yes"){
        tempIsPremium = true;
    }
    else{
        tempIsPremium = false;
    }
    master.setIsPremium(tempIsPremium);
    if(tempIsPremium == true){
    cout << "Vvedite razmer premii:" << endl;
    cin >> tempPrice;
    master.setPremium(tempPrice);
    cout << "Vsego rabochyh calendarnyh dney:" << endl;
    cout << master.getCalendarWorkingDays() << endl;
    cout << "Otrabotannyh dney:" << endl;
    cout << master.getWorkingDays() << endl;
    cout <<"Vyrabotka rabotnika:" << endl;
    cout << (long int)master.getMasterProfit() << endl;
    cout <<"Premiya" << endl;
    cout << (long int)master.getPremium() << endl;
    cout <<"Polnaya zarabotnaya plata directora:" << endl;
    cout << (long int)master.calculateTotalSalary() << endl;
    }
    else{
    cout << "Vsego rabochyh calendarnyh dney:" << endl;
    cout << master.getCalendarWorkingDays() << endl;
    cout << "Otrabotannyh dney:" << endl;
    cout << master.getWorkingDays() << endl;
    cout <<"Vyrabotka rabotnika:" << endl;
    cout << (long int)master.getMasterProfit() << endl;
    cout <<"Premiya" << endl;
    cout << (long int)master.calculatePremium() << endl;
    cout <<"Polnaya zarabotnaya plata directora:" << endl;
    cout << (long int)master.calculateTotalSalary() << endl;
}
*/






}
