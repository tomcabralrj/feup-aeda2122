#include "postOffice.h"
#include <string>

PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}


//--------

// TODO
vector<Mail *> PostOffice::removePostman(string name) {
	vector<Mail *> res;
    for(int i=0; i<postmen.size(); i++){
        if(postmen[i].getName() == name){
            res = postmen[i].getMail();
            postmen.erase(postmen.begin()+i);
            break;
        }
    }
	return res;
}

// TODO
vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {
	vector<Mail *> res;
    balance = 0;
    for(auto i: mailToSend){
        balance += i->getPrice();
        if(i->getZipCode() >= this->firstZipCode && i->getZipCode() <= this->lastZipCode){
            addMailToDeliver(i);
        }else{
            res.push_back(i);
        }
    }
    mailToSend.clear();
	return res;
}


Postman PostOffice::addMailToPostman(Mail *m, string name) {
	for(auto i: postmen){
        if(i.getName() == name){
            i.addMail(m);
            return i;
        }
    }
    throw NoPostmanException(name);
}

