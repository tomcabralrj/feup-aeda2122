#include "mail.h"

Mail::Mail(string send, string rec, string zcode):
			sender(send),receiver(rec), zipCode(zcode)
{ }

Mail::~Mail()
{ }

string Mail::getZipCode() const {
	return zipCode;
}


RegularMail::RegularMail(string send, string rec, string zcode, unsigned int w):
			Mail(send, rec, zcode), weight(w)
{ }


GreenMail::GreenMail(string send, string rec, string zcode, string t):
			Mail(send, rec, zcode), type(t)
{ }


unsigned int RegularMail::getWeight() const {
    return weight;
}


string GreenMail::getType() const{
    return type;
}



//--------

// TODO
unsigned int Mail::getPrice() const {
    return 0;
}

unsigned int RegularMail::getPrice() const {
    if(getWeight() <= 20){
        return 50;
    }else if(getWeight() > 20 && getWeight() <= 100){
        return 75;
    }else if(getWeight() > 100 && getWeight() <= 500){
        return 140;
    }else{
        return 325;
    }
}

unsigned int GreenMail::getPrice() const {
    if(getType() == "envelope"){
        return 80;
    }else if(getType() == "bag"){
        return 200;
    }else{
        return 240;
    }
}
