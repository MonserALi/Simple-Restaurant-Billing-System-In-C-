
#include<bits/stdc++.h>
using namespace std;

/// Declare Class Question Number 1
class Restaurant{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
protected:
    double total_tax;

public:
    Restaurant(){

        total_tax =0;
    }

    void set_total_tax(double n){
        total_tax += n;
    }

    void get_total_tax(){
        cout<<total_tax;
    }
};

/// take input question Number 2

void take_input(int n,Restaurant *restaurant){

     for(int i=0;i<n;i++){
        cout<<"Enter item "<<i+1<<" Code : "<<endl;
        cin>>restaurant->food_item_codes[i];
        cout<<"Enter item "<<i+1<<" Name : "<<endl;
        cin.ignore();
        getline(cin,restaurant->food_item_names[i]);
        cout<<"Enter item "<<i+1<<" Price : "<<endl;
        cin>>restaurant->food_item_prices[i];
    }
}

///  Show all item details Question number 3
void make_bill(Restaurant *restaurant,int n){

    cout<<endl<<string(35,' ')<<"Make Bill"<<endl;
    cout<<string(25,' ')<<"_____________________________"<<endl;
    cout<<"Item Code"<<string(14,' ')<<"Item Name"<<string(25,' ')<<"Item Price"<<endl;
    for(int i=0;i<n;i++){
        int z  = restaurant->food_item_names[i].size();
        cout<<restaurant->food_item_codes[i]<<string(20,' ')<<restaurant->food_item_names[i]<<string(34-z,' ')<<restaurant->food_item_prices[i]<<endl;
    }
}
/// Take Order from Customer Question Number 4
void take_order(Restaurant *restaurant,int n){
    cout<<"\n\nEnter Table Number : ";
    int table_number;
    cin>>table_number;
    cout<<"Enter Number of Item : ";
    int number_of_item;
    cin>>number_of_item;
    int item_code[number_of_item];
    int item_quantity[number_of_item];

    int total_price[number_of_item];
    double grand_tatal = 0;


    for(int i=0;i<number_of_item;i++){
        //
        f:
        cout<<"Enter Item "<<i+1<<" Code : ";
        int cnt = 0;

        cin>>item_code[i];
        for(int j=0;j<n;j++){
            if(item_code[i]==restaurant->food_item_codes[j]){
               cnt++;
            }
        }
        if(cnt==0){
                cout<<"Invalid Code See above roster and try with valid code !"<<endl;
            goto f;
        }
        cout<<"Enter Item "<<i+1<<" Quantity : ";
        cin>>item_quantity[i];
    }
    /// find all ordered item from  make bill Question Number 5

       cout<<endl<<string(40,' ')<<"Bill Summary"<<endl;
    cout<<string(30,' ')<<"____________________________"<<endl;
    cout<<"Table No. : "<<table_number<<endl;
    cout<<"Item Code"<<string(5,' ')<<"Item Name"<<string(20,' ')<<"Item Price"<<string(10,' ')<<"Item Quantity" <<string(10,' ' )<<"Total Price "<<endl;
    for(int i =0 ; i<number_of_item;i++){
            for(int j=0;j<n;j++){
                 if(restaurant->food_item_codes[j]==item_code[i]){
                    int z  = restaurant->food_item_names[j].size();
                    total_price[i] = restaurant->food_item_prices[j]*item_quantity[i];
                    cout<<restaurant->food_item_codes[j]<<string(10,' ')<<restaurant->food_item_names[j]<<string(30-z,' ')<<restaurant->food_item_prices[j]<<string(17,' ')<<item_quantity[i]<<string(22,' ')<<total_price[i]<<endl;
                    grand_tatal+= total_price[i];
                }
            }
    }
    /// Calculate 5% of tax and show in bill Summary Question Number 6
    double tax = grand_tatal*0.05;
    cout<<"TAX "<<string(82,' ')<<fixed<<setprecision(2)<<tax;
    double net_total = grand_tatal+tax;
    cout<<endl<<string(110,'_');
    cout<<"\nNet Total " <<string(75,' ')<<fixed<<setprecision(2) <<net_total<<"  Taka"<<endl;

    /// add total tax to restaurant class Question Number 7

    restaurant->set_total_tax(tax);
}

int main(){
    int n;
    cout<<"Enter Number of Item : ";
    cin>>n;
    Restaurant *restaurant = new Restaurant();

    take_input(n,restaurant);

    flag:
        make_bill(restaurant,n);
        take_order(restaurant,n);
    goto flag;

return 0;
}


