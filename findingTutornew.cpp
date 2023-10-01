#include<bits/stdc++.h>
using namespace std;

class Tutor{      //abstract class using as interface
    protected:    //using encapsulation
    int tcode,days;
    float fee,hour;
    string tfname,tlname,sub,phn,inst,gender;

    public:
    virtual void menu()=0;   // using pure virtual function
};

class Admin:public Tutor{  //using inheritance
    public:
    void menu();
    void admin();
    void total_tutor();
    void add();
    void edit();
    void rem();
    void student();
    void findtutor();
    void display();
};

template<class T>  //using template
void tutor_count(vector<T> &v){   //using stl
    int total=0;

   for(int i=0; i<v.size(); i++){
        total+=v[i];
   }

    cout<<"Total number of tutor available: "<<
    total<<endl;
}

void Admin::total_tutor()
{
     fstream data;
     vector<int> v;
    data.open("tutorinfo.txt",ios::in);  //using file handling
     if(!data){

        cout<<"Database doesn't exist!!!"<<endl;
    }
    else
    {
        data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;
        while(!data.eof()){
             v.push_back(1);
            data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;


        }
    data.close();
    }

    tutor_count(v);
}


void Admin::menu(){
    A:
    int choice;
    string mail,pass;

    cout<<endl;
    cout<<"_____________________________"<<endl;
    cout<<"|       Find A Tutor!!      |"<<endl;
    cout<<"|___________________________|"<<endl;

    cout<<"1. Use as Admin."<<endl;
    cout<<"2. Use as a Student."<<endl;
    cout<<"3. Exit."<<endl;
    cout<<"Please select one:"<<endl;
    cin>>choice;

    switch(choice){

        case 1:

            cout<<endl;
            cout<<"_______Please Login______"<<endl;
            cout<<"Enter Email:"<<endl;
            cin>>mail;
            cout<<"Enter password:"<<endl;
            cin>>pass;

            if(mail=="tutor@email.com" && pass=="tutor"){
                admin();
            }
            else{
                cout<<"WRONG EMAIL/PASSWORD !!!"<<endl;
            }

        break;

        case 2:
            student();
        break;

        case 3:
            exit(0);
        break;

        default:
            cout<<"Please select from the given options !!!"<<endl;
    }

    goto A;
}
void Admin::admin()
    {
        A:
            int choice;
            cout<<endl;
            cout<<"-----------admin panel-----------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"1.Add tutor."<<endl;
            cout<<"2.Remove tutor from database."<<endl;
            cout<<"3.Edit database."<<endl;
            cout<<"4.View database."<<endl;
            cout<<"5.See total number of available tutor."<<endl;
            cout<<"6.go to menu"<<endl;
            cout<<"choose any of the options: "<<endl;
            cin>>choice;
             switch(choice){
        case 1:
            add();
        break;

        case 2:
            rem();
        break;

        case 3:
            edit();
        break;

        case 4:
            display();
        break;

        case 5:
            total_tutor();
        break;

        case 6:
            menu();
        break;

        default:
            cout<<"Please select from the given options !!!"<<endl;
    }

    goto A;
}
void Admin::student()
{
    A:
    int choice;

    cout<<endl;
    cout<<"---------Welcome-------"<<endl;
    cout<<"1. Book tutor."<<endl;
    cout<<"2. Back to Main Menu."<<endl;
    cout<<"3. Exit."<<endl;
    cout<<"Please select one:"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            findtutor();
        break;

        case 2:
            menu();
        break;

        case 3:
            exit(0);
        break;

        default:
            cout<<"Please select from the given options !!!"<<endl;
    }

    goto A;

}
void Admin::add()
{
     A:
    int code,d,flag=0;
    float f,hrs;
    string tfn,tln,g,i1,s,ph;
    cout<<"enter tuitor's code: "<<endl;
    cin>>tcode;
    cout<<"enter tutor's first name: "<<endl;
    cin>>tfname;
    cout<<"enter tutor's last name: "<<endl;
    cin>>tlname;
    cout<<"enter tuitor's gender: "<<endl;
    cin>>gender;
    cout<<"enter tuitor's instituition(example:BUET,KUET): "<<endl;
    cin>>inst;
    cout<<"Enter subjects he/she can teach(example:physics,chemistry): "<<endl;
    cin>>sub;
    cout<<"Enter number of days he/she can tuitor: "<<endl;
    cin>>days;
    cout<<"Enter number of hours he/she can tuitor(example:2.5,3.0): "<<endl;
    cin>>hour;
    cout<<"Enter required payment: "<<endl;
    cin>>fee;
    cout<<"Enter tutor's phone number: "<<endl;
    cin>>phn;
    fstream data;

    data.open("tutorinfo.txt", ios::in);

    if(!data){

        data.open("tutorinfo.txt", ios::out|ios::app);

        data<<" "<<tcode<<" "<<tfname<<" "<<tlname<<" "<<gender<<" "<<inst<<" "<<sub<<" "<<days<<" "<<hour<<" "<<fee<<" "<<phn<<"\n";

        data.close();
    }
else{
        data>>code>>tfn>>tln>>g>>i1>>s>>d>>hrs>>f>>ph;

        while(!data.eof()){

            if(code==tcode){
                flag++;
            }
            data>>code>>tfn>>tln>>g>>i1>>s>>d>>hrs>>f>>ph;
        }
        data.close();

        if(flag==1){
            cout<<"Duplicate tutor Code Detected!"<<endl;
            goto A;
        }
         else{
            data.open("tutorinfo.txt", ios::out|ios::app);

            data<<" "<<tcode<<" "<<tfname<<" "<<tlname<<" "<<gender<<" "<<inst<<" "<<sub<<" "<<days<<" "<<hour<<" "<<fee<<" "<<phn<<"\n";

            data.close();
        }
    }


    cout<<"Database Updated Successfully."<<endl;
}
void Admin::rem()
{
     A:
    int key,flag=0;

    fstream data,newdata;
    data.open("tutorinfo.txt",ios::in);
     if(!data){

        cout<<"Database doesn't exist!!!"<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"--------Remove tutor--------"<<endl;
        display();
        cout<<"Enter tutor's code you want to remove: "<<endl;
        cin>>key;
        newdata.open("tutorinfo1.txt",ios::out|ios::app);
        data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;
        while(!data.eof())
        {
            if(key==tcode)
            {
                cout<<"Removed successfully!!"<<endl;
                flag++;
            }
            else
            {
                newdata<<" "<<tcode<<" "<<tfname<<" "<<tlname<<" "<<gender<<" "<<inst<<" "<<sub<<" "<<days<<" "<<hour<<" "<<fee<<" "<<phn<<"\n";

            }
            data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;

        }

        data.close();
        newdata.close();

        remove("tutorinfo.txt");
        rename("tutorinfo1.txt","tutorinfo.txt");
        if(flag==0){
            cout<<"Record not found !!!"<<endl;
        }
    }

}
void Admin::edit()
{
     A:
    int key,code,d,flag=0;
    float f,hrs;
    string tfn,tln,g,i1,s,ph;
    fstream data,newdata;
    data.open("tutorinfo.txt",ios::in);
     if(!data){

        cout<<"Database doesn't exist!!!"<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"--------Edit tutor info--------"<<endl;
        display();
        cout<<"Enter tutor's code you want to edit: "<<endl;
        cin>>key;
        newdata.open("tutorinfo1.txt",ios::out|ios::app);
        data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;
        while(!data.eof())
        {
            if(key==tcode)
            {
                cout<<"Enter tutor's new code: "<<endl;
                cin>>code;
                cout<<"Enter tutor's first name: "<<endl;
                cin>>tfn;
                cout<<"Enter tutor's last name: "<<endl;
                cin>>tln;
                cout<<"Enter tutor's gender: "<<endl;
                cin>>g;
                cout<<"Enter tutor's instituition(example:BUET,KUET): "<<endl;
                cin>>i1;
                cout<<"Enter subjects he/she can teach(example:physics,chemistry): "<<endl;
                cin>>s;
                cout<<"Enter number of days per week he/she can tutor: "<<endl;
                cin>>d;
                cout<<"Enter number of hours he/she can tutor(example:2.5,3.0): "<<endl;
                cin>>hrs;
                cout<<"Enter required payment: "<<endl;
                cin>>f;
                cout<<"Enter tutor's phone number: "<<endl;
                cin>>ph;
                newdata<<" "<<code<<" "<<tfn<<" "<<tln<<" "<<g<<" "<<i1<<" "<<s<<" "<<d<<" "<<hrs<<" "<<f<<" "<<ph<<"\n";

                cout<<"Database edited!"<<endl;
            flag++;

            }
            else
            {
                newdata<<" "<<tcode<<" "<<tfname<<" "<<tlname<<" "<<gender<<" "<<inst<<" "<<sub<<" "<<days<<" "<<hour<<" "<<fee<<" "<<phn<<"\n";

            }
            data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;

        }

        data.close();
        newdata.close();

        remove("tutorinfo.txt");
        rename("tutorinfo1.txt","tutorinfo.txt");
        if(flag==0){
            cout<<"Record not found !!!"<<endl;
        }
    }

}
void Admin::display()
{
     fstream data;
    data.open("tutorinfo.txt",ios::in);
     if(!data){

        cout<<"Database doesn't exist!!!"<<endl;
    }
    else
    {
        data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;
        while(!data.eof()){

            cout<<"Code: "<<tcode<<"\t\t"<<"Name: "<<tfname<<" "<<tlname<<"\t\t"<<"Gender: "<<gender<<"\t\t"<<"Institution: "<<inst<<"\t\t"<<"Subject: "<<sub<<"\t\t"<<"Days: "<<days<<"\t\t"<<"Hours: "<<hour<<"\t\t"<<"Payment: "<<fee<<"\t\t"<<"Cont. no.: "<<phn<<endl<<endl;
            data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;

        }
    data.close();
    }
}
void Admin::findtutor()
{
    A:
        int key,flag=0;
        string sfname,slname,sphn,sclass;

        fstream data,sdata;
        data.open("tutorinfo.txt",ios::in);
     if(!data){

        cout<<"Database doesn't exist!!!"<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"--------Book tutor--------"<<endl;
        display();
        cout<<"Enter tutor's code you want to book: "<<endl;
        cin>>key;
        data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;
        while(!data.eof())
        {
            if(key==tcode)
            {
                cout<<"Enter your first name: "<<endl;
                cin>>sfname;
                cout<<"Enter your last name: "<<endl;
                cin>>slname;
                cout<<"Enter your class: "<<endl;
                cin>>sclass;
                cout<<"enter your contact number: "<<endl;
                cin>>sphn;
                cout<<endl;
                cout<<"Name: "<<sfname<<" "<<slname<<endl;
                cout<<"class: "<<sclass<<endl;
                cout<<"Phone: "<<sphn<<endl;
                cout<<"Tutor's Code: "<<tcode<<endl;
                cout<<"Name of the tutor : "<<tfname<<" "<<tlname<<endl;
                cout<<"days: "<<days<<endl;
                cout<<"duration: "<<hour<<endl;
                cout<<"payment: "<<fee<<endl;
                cout<<"tutor's phone: "<<phn<<endl;

                sdata.open("receipt.txt",ios::out);
                sdata<<"Name: "<<sfname<<" "<<slname<<"\nPhone: "<<sphn<<"\nCode: "<<tcode<<"\nDuration: "<<hour<<"\nPayment: "<<fee<<"\n";

                cout<<"Tutor booking Done"<<endl;

                flag=1;

                break;


            }
            data>>tcode>>tfname>>tlname>>gender>>inst>>sub>>days>>hour>>fee>>phn;


        }

        int choice;
        if(flag==0){
            cout<<"Try to enter correct tutor code"<<endl;
            cout<<"Press 1 to continue"<<endl;
            cout<<"Press 2 to return to main menu"<<endl;
            cin>>choice;

            if(choice==1){
                goto A;
            }
            else{
                menu();
            }
        }

        sdata.close();



    }


}



int main(){
    Admin obj;

    obj.menu();
}
