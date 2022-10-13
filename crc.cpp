#include <iostream>
using namespace std;



// XOR for modulo2 division
string xor1(string a, string b)
{
    string str = "";
    int n = b.length();
    for(int i=1; i<n; i++){
        if(a[i] == b[i])
            str += "0";
        else
            str += "1";
    }
    return str;
}

string mod2div(string msg, string key){

    int mlen = msg.length();
    int klen = key.length();
    string temp = msg.substr(0, klen);
    while(klen < mlen){
        if(temp[0] == '1')
            temp = xor1(temp,key)+ msg[klen]; 
        else
            temp = xor1(string(klen, '0'), temp) + msg[klen];
        klen += 1;
    }

    //after last iteration, XOR of remaining bits
    if(temp[0] == '1')
        temp = xor1(temp, key);
    else
        temp = xor1(string(klen,'0'), temp);
    
    return temp;
}

string sender(string msg, string key){

    cout << "Your Message : " << msg << endl;
    cout << "Your Key : " << key << endl;

    int klen = key.length()-1;
    string nmsg = msg+string(klen, '0');

    string remainder = mod2div(nmsg, key);
    cout<<"remainder : "<<remainder<<endl;
    cout << "Message sent : " << msg+remainder << endl << endl;
    return msg+remainder;   // returns msg+remainder
}
void receiver(string msg, string key){
    cout << "Received Message : " << msg << endl;
    cout << "Key : " << key << endl;
    cout << "Checking Received Message..." << endl;
    string check = mod2div(msg, key);

    int klen = key.length()-1;
    if(check == string(klen, '0'))
        cout << "Message Succesfully Received :)" << endl;
    else
        cout << "There is some data Lost :(" << endl;

}
int main()
{
    string msg;
    string key;
    label:
    cout << "Enter the data to send (In Binary) : ";
    cin >> msg;
    
    cout << "Enter a key (In Binary) : ";
    cin >> key;
    
    string msgR = sender(msg, key);
    receiver(msgR, key);
    return 0;
}