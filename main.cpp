#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class shopping{
   private:
     int codeProduct;
     string nameProduct;
     float priceProduct;
     float discount;
   public:
    
    void menu();
    void admin();
    void customer();
    void addProduct();
    void removeProduct();
    void updateProduct();
    void showProduct();
    void showProductRec();
    void reciept();
};

void shopping::menu(){
    int choice;
    string password;
    string email;
    cout<<"\t\t\t************************************************\n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t                Main Menu                       \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t************************************************\n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t1. Administrator                  \n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t2. Customer                       \n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t3. Exit                           \n";

    cout<<"\n\n";
    cout<<"\t\t\tEnter your choice: ";
    cin>>choice;

    switch(choice){
        case 1: 
            cout<<"\t\tPlease Login         "<<endl;
            cout<<"\t\tEnter email: ";
            cin>>email;

            cout<<"\t\tEnter password: ";
            cin>>password;
            if(email=="amrithaathulya0210@gmail.com" && password=="amritha0210"){
                admin();
            }
            else{
                cout<<"\t\t\tInvalid email or password";
                menu();
            }
            break;
        case 2:
               customer();
               break;
        case 3:
                exit(0);
                break;
        default:
                cout<<"\t\t\tInvalid choice                  \n";
                cout<<"\t\t\tPlease select from given choices";
                menu();
                break;
    }
}

void shopping::admin(){
    int choice;
    cout<<"\n\n\n";
    cout<<"\t\t\t************************************************\n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t                Administrator Menu              \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t************************************************\n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t1. Add Product                                 \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t2. Remove Product                              \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t3. Update Product                              \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t4. Exit                                         \n";
    cout<<"\t\t\t                                                \n";
   
    cout<<"\t\t\tEnter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
            addProduct();
            break;
        case 2:
            removeProduct();
            break;
        case 3:
            updateProduct();
            break;
        
        case 4:
            menu();
            break;
        default:
            cout<<"\t\t\tInvalid choice                  \n";
            cout<<"\t\t\tPlease select from given choices";
            admin();
            break;
    }
}

void shopping::customer(){
    int choice;
    cout<<"\n\n\n";
    cout<<"\t\t\t************************************************\n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t                Customer Menu                   \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t************************************************\n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t1. Show Product                                \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t2. Reciept                                     \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t3. Exit                                        \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\tEnter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
            showProduct();
            break;
        case 2:
            reciept();
            break;
        case 3:
            menu();
            break;
        default:
            cout<<"\t\t\tInvalid choice                  \n";
            cout<<"\t\t\tPlease select from given choices";
            customer();
            break;
    }
}

void shopping::addProduct(){
    
    fstream data;
    int c;
    int token=0;
    string name;
    float p;
    float d;
    cout<<"\n\n\t\t\tAdd new product\n";
    cout<<"\t\t\tEnter code of the product: ";
    cin>>c;
    cout<<"\t\t\tEnter name of the product: ";
    cin>>name;
    cout<<"\t\t\tEnter price of the product: ";
    cin>>p;
    cout<<"\t\t\tEnter discount on the product: ";

    cin>>d;
    data.open("product.txt",ios::in);
    if(!data){
        data.open("product.txt",ios::app|ios::out);
        data<<c<<" "<<name<<" "<<p<<" "<<d<<endl;
        data.close();
    }
    else{
        data>>codeProduct>>nameProduct>>priceProduct>>discount;
        while(!data.eof()){
            //data>>c>>name>>p>>d;
            if(c==codeProduct){
                token++;
            }
            data>>codeProduct>>nameProduct>>priceProduct>>discount;
        }
        data.close();
    
    if(token==1){
        cout<<"\t\t\tProduct already exists\n";
        addProduct();
    }
    else{
        data.open("product.txt",ios::app|ios::out);
        data<<" "<<c<<" "<<name<<" "<<p<<" "<<d<<endl;
        data.close();
    }
    }
     cout<<"\t\t\tProduct added successfully\n";
     admin();
    }

void shopping::updateProduct(){
    int c;
    int token=0;
    string name;
    float p;
    float d;
    fstream data;
    fstream temp;
    cout<<"\n\n\t\t\tUpdate product\n";
    cout<<"\t\t\tEnter code of the product: ";
    cin>>c;
    
    data.open("product.txt",ios::in);
    if(!data){
        cout<<"\t\t\tProduct not found\n";
        updateProduct();
    }
    
    else{
        temp.open("temp.txt",ios::app|ios::out);
        data>>codeProduct>>nameProduct>>priceProduct>>discount;
        while(!data.eof()){
            //data>>c>>name>>p>>d;
            if(c==codeProduct){
                token++;
                cout<<"\t\t\tEnter new product code: ";
                cin>>c;
                cout<<"\t\t\tEnter name of the product: ";
                cin>>name;
                cout<<"\t\t\tEnter price of the product: ";
                cin>>p;
                cout<<"\t\t\tEnter discount on the product: ";
                cin>>d;
                temp<<" "<<c<<" "<<name<<" "<<p<<" "<<d<<endl;
            }
            else{
                temp<<" "<<codeProduct<<" "<<nameProduct<<" "<<priceProduct<<" "<<discount<<endl;
            }
            data>>codeProduct>>nameProduct>>priceProduct>>discount;
        }
        data.close();
        temp.close();
        remove("product.txt");
        rename("temp.txt","product.txt");

        if(token==0){
            cout<<"\t\t\tProduct not found\n";
            
        }
        else{
            cout<<"\t\t\tProduct updated successfully\n";
        }
      char c;
      cout<<"\t\t\tDo you want to continue(y/n)? : ";
      cin>>c;
      if(c=='y'||c=='Y'){
      	updateProduct();
	  }
	  else{
	  	admin();
	  }
      
    }
    
}
void shopping::removeProduct(){
    fstream data,temp;
    int c;  
    int token=0;
    cout<<"\n\n\t\t\tRemove product\n";
    cout<<"\t\t\tEnter code of the product: ";
    cin>>c;
    data.open("product.txt",ios::in);
    if(!data){
        cout<<"\t\t\tProduct not found\n";
       
    }

    else{
        temp.open("temp.txt",ios::app|ios::out);
        data>>codeProduct>>nameProduct>>priceProduct>>discount;
        while(!data.eof()){
            //data>>c>>name>>p>>d;
            if(c==codeProduct){
                token++;
            }
            else{
                temp<<" "<<codeProduct<<" "<<nameProduct<<" "<<priceProduct<<" "<<discount<<endl;
            }
            data>>codeProduct>>nameProduct>>priceProduct>>discount;
        }
        data.close();
        temp.close();
        remove("product.txt");
        rename("temp.txt","product.txt");
        if(token==0){
            cout<<"\t\t\tProduct not found\n";
            char c;
            cout<<"\t\t\tDo you want to continue?(y/n) :";
            cin>>c;
            if(c=='y'||c=='Y'){
            	removeProduct();
			}
			else{
				admin();
			}
        }
        else{
            cout<<"\t\t\tProduct removed successfully\n";
            char c;
            cout<<"\t\t\tDo you want to continue?(y/n) :";
            cin>>c;
            if(c=='y'||c=='Y'){
            	removeProduct();
			}
			else{
				admin();
			}
        }
    }
}
void shopping::showProduct(){
    fstream data;
    data.open("product.txt",ios::in);
    if(!data){
        cout<<"\t\t\tNo product found\n";
    }
    else{
        data>>codeProduct>>nameProduct>>priceProduct>>discount;
        while(!data.eof()){
            cout<<"\t\t\t**********************"<<endl;
            cout<<"\t\t\tCode: "<<codeProduct<<endl;
            cout<<"\t\t\tName: "<<nameProduct<<endl;
            cout<<"\t\t\tPrice: "<<priceProduct<<endl;
            cout<<"\t\t\tDiscount: "<<discount<<endl;
            cout<<"\t\t\t**********************"<<endl;
            data>>codeProduct>>nameProduct>>priceProduct>>discount;
        }
    }
    data.close();
    char c;
    cout<<"\t\t\tDo you want to continue?(y/n): ";
    cin>>c;
    if(c=='y'||c=='Y'){
        customer();
    }
    else{
        menu();
    }

}
void shopping::showProductRec(){
    fstream data;
    data.open("product.txt",ios::in);
    if(!data){
        cout<<"\t\t\tNo product found\n";
    }
    else{
        data>>codeProduct>>nameProduct>>priceProduct>>discount;
        while(!data.eof()){
            cout<<"\t\t\t**********************"<<endl;
            cout<<"\t\t\tCode: "<<codeProduct<<endl;
            cout<<"\t\t\tName: "<<nameProduct<<endl;
            cout<<"\t\t\tPrice: "<<priceProduct<<endl;
            cout<<"\t\t\tDiscount: "<<discount<<endl;
            cout<<"\t\t\t**********************"<<endl;
            data>>codeProduct>>nameProduct>>priceProduct>>discount;
        }
    }
    data.close();
    

}
void shopping:: reciept(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amt=0;
    float d=0;
    int total=0;
    cout<<"\n\n\t\t\tReciept\n";
    data.open("product.txt",ios::in);
    if(!data){
        cout<<"\t\t\tNo product found\n";
    }
    else{
        data.close();
        showProductRec();
    cout<<"\t\t\t************************************************\n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t    Please place the order                       \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t************************************************\n";
    cout<<"\t\t\t                                                \n";
    while(1){
        cout<<"\t\t\tEnter code of the product: ";
        cin>>arrc[c];
        cout<<"\t\t\tEnter quantity of the product: ";
        cin>>arrq[c];
        c++;
        cout<<"\t\t\tDo you want to continue?(y/n): ";
        cin>>choice;
        if(choice=='n'||choice=='N'){
            break;
        }

    }
    cout<<"\t\t\t                                                \n";

    cout<<"\t\t\t************************************************\n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t    Your order is                               \n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t************************************************\n";

    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\tCode\t\tName\t\tPrice\t\tQuantity\t\tAmount\t\tAmount with discount\n";
    cout<<"\t\t\t                                                \n";
    cout<<"\t\t\t                                                \n";
    for(int i=0;i<c;i++){
        data.open("product.txt",ios::in);
        data>>codeProduct>>nameProduct>>priceProduct>>discount;
        while(!data.eof()){
            if(arrc[i]==codeProduct){
               
                amt=arrq[i]*priceProduct;
                d=amt-(amt*discount/100);
                total+=d;
                cout<<"\t\t\t"<<codeProduct<<"\t\t"<<nameProduct<<"\t\t"<<priceProduct<<"\t\t"<<arrq[i]<<"\t\t"<<amt<<"\t\t"<<d<<endl;
            }
            data>>codeProduct>>nameProduct>>priceProduct>>discount;
        }
        data.close();
        cout<<"\t\t\t                                                \n";
        cout<<"\t\t\t                                                \n";
        cout<<"\t\t\t************************************************\n";
        
    }
    cout<<"\t\t\tTotal amount: "<<total<<endl; 
    char c;
    cout<<"\t\t\tDo you want to continue?(y/n): ";
    cin>>c;
    if(c=='y'||c=='Y'){
        customer();
    }
    else{
        menu();
    }
}
}
int main(int argc, char const *argv[]){
    shopping s;
    s.menu();
    return 0;
}