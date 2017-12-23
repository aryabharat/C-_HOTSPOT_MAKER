/* C++ Program to host a hotspot using command promt and batch file */
#include<bits/stdc++.h>
using namespace std;
void start_HS();//start hotspot
void stop_HS();// stop hotspot
void restart_HS();// restart with previous setting
string s;

int main()
{   int temp;
    char c='y';
    while(c=='y'||c=='Y')//for refreshing the main
    {
        system("CLS");
    cout<<"***********************************************************************************************************************\n\n";
    cout<<"\t\t\t**************************HOTSPOT MAKER IN C++**************************\n\n";
    cout<<"***********************************************************************************************************************\n\n";
    cout<<"Press [1] to START HOTSPOT\n";
    cout<<"Press [2] to RESTART HOTSPOT\n";
    cout<<"Press [3] to STOP HOTSPOT\n";
    cin>>temp;
    if(temp==1)
        start_HS();
        else if(temp==2)
            restart_HS();
            else if(temp==3)
                stop_HS();
                    else
                        cout<<"INVALID OPTION\n";

                        cout<<"PRESS [y] OR [Y] TO START AGAIN\t";
                        cin>>c;
    }
   system("CLS");
    cout<<"\n\n\t\t***THANKYOU***";
   return 0;
}
void restart_HS()
{
    system("CLS");
    cout<<"********************************************RESTART HOTSPOT************************************************************\n\n";
  string line;
  fstream file;
  file.open("data.txt");//check if hotspot is created before
  if(file.is_open())
  {
      getline (file,line);
      file.close();
  }
 else
 {cout << "Unable to RESTART\n";return;}// else it will not create

    file.open("test.bat",ios::out|ios::trunc);//create hotspot with previous setting
    file<<line;
    file.close();
    system("test.bat");
    system("netsh wlan start hostednetwork");
}
void stop_HS()
{ system("CLS");
    cout<<"***********************************************STOP HOTSPOT************************************************************\n\n";
    system("netsh wlan stop hostednetwork");//simple system call to stop hotspot.
}
void start_HS()
{system("CLS");
    cout<<"**********************************************START HOTSPOT************************************************************\n\n";

    string name,pw;
    s="netsh wlan set hostednetwork mode=allow ssid=";//command for hotspot
        cout<<"Enter HOTSPOT Name(ssid)\t\t";//input the hotspot name and password
        cin>>name;
    s=s+name+" key=";
        cout<<"Enter PASSWORD,b/w 8-64 char\t\t";
        cin>>pw;
        while(pw.size()<8)
        {
            cout<<"PASSWORD DOES NOT MATCH THE SIZE \n"<<"Enter again\n";
            cin>>pw;
        }
   s=s+pw;
    fstream file;
    file.open("data.txt",ios::out);//make a data file for password and ssid
    file<<s;
    file.close();
    file.open("test.bat",ios::out | ios::trunc);//make a batch file for hotspot command
    file<<s;
    file.close();
    system("test.bat");//system call to host hotspot with given setting
    system("netsh wlan start hostednetwork");//system command to start the hostednetwork
    system("pause");
}
