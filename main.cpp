#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Persoana{
protected:
    int id;
    string nume;
public:
    Persoana(){
        id=0;
        nume="EMPTY";
    }
    //Comment
    
    Persoana(int id, string nume){
        this->id=id;
        this->nume=nume;
    }
    virtual ~Persoana(){}

    int getId(){
        return id;
    }
    string getNume(){
        return nume;
    }
    void setNume(string nume){
        this->nume=nume;
    }
    void setId(int id){
        this->id=id;
    }
    virtual ostream& print(ostream& os) const {
        os << id << endl;
        os << nume << endl;
        return os;
    }
    virtual Persoana* clone() const {
        return new Persoana(*this);
    }
    friend istream& operator>>(istream& is, Persoana& persoana){
        is >> persoana.id;
        is >> persoana.nume;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Persoana& persoana){
        return persoana.print(os);
    }
};
class Abonat: public Persoana{
protected:
    string nr_telefon;
public:
    Abonat(): Persoana(){
        nr_telefon="EMPTY";
    }
    Abonat(int id,string nume,string nr_telefon): Persoana(id, nume), nr_telefon(nr_telefon){}
    string getNr_Telefon(){
        return nr_telefon;
    }
    virtual ~Abonat(){}
    void setNr_Telefon(string nr_telefon){
        this->nr_telefon=nr_telefon;
    }
    virtual ostream& print(ostream& os) const override {
        Persoana::print(os);
        os << nr_telefon << endl;
        return os;
    }
    Abonat* clone() const override {
        return new Abonat(*this);
    }
    friend ostream& operator<<(ostream& os, const Abonat& abonat){
        return abonat.print(os);
    }
    friend istream& operator>>(istream& is, Abonat& abonat){
        is >> static_cast<Persoana&>(abonat);
        is >> abonat.nr_telefon;
        return is;
    }

//    in >> dreptunghi.laturaMica >> dreptunghi.laturaMare;
//    in >> dynamic_cast<Forma&>(dreptunghi);
//    return in;
};
class Abonat_Skype:public Abonat{
protected:
    string id_skype;
public:
    Abonat_Skype():Abonat(){
        id_skype="EMPTY";
    }
    Abonat_Skype(int id, string nume, string nr_telefon,string id_skype): Abonat(id, nume, nr_telefon), id_skype(id_skype){}
    string getId_Skype(){
        return id_skype;
    }
    virtual ~Abonat_Skype(){}
    void setId_Skype(string id_skype){
        this->id_skype=id_skype;
    }
    virtual ostream& print(ostream& os) const override {
        Abonat::print(os);
        os << id_skype << endl;
        return os;
    }
    Abonat_Skype* clone() const override {
        return new Abonat_Skype(*this);
    }

    friend ostream& operator<<(ostream& os, const Abonat_Skype& abonat_skype){
        return abonat_skype.print(os);
    }
    friend istream& operator>>(istream& is, Abonat_Skype& abonat_skype){
        is>>abonat_skype.id;
        is>>abonat_skype.nume;
        is>>abonat_skype.nr_telefon;
        is>>abonat_skype.id_skype;
        return is;
    }
};
class Abonat_Skype_Romania:public Abonat_Skype{
protected:
    string adresa_mail;
public:
    Abonat_Skype_Romania():Abonat_Skype(){
        adresa_mail="EMPTY";
    }
    Abonat_Skype_Romania(int id, string nume, string nr_telefon, string id_skype, string adresa_mail):Abonat_Skype(id, nume, nr_telefon,id_skype),adresa_mail(adresa_mail){}
    string getAdresa_Mail(){
        return adresa_mail;
    }
    virtual ~Abonat_Skype_Romania(){}
    void setAdresa_Mail(string adresa_mail){
        this->adresa_mail=adresa_mail;
    }
    virtual ostream& print(ostream& os) const override {
        Abonat_Skype::print(os);
        os << adresa_mail << endl;
        return os;
    }
    Abonat_Skype_Romania* clone() const override {
        return new Abonat_Skype_Romania(*this);
    }
    friend ostream& operator<<(ostream& os, const Abonat_Skype_Romania& abonat){
        return abonat.print(os);
    }
    friend istream& operator>>(istream& is, Abonat_Skype_Romania& abonat_skype){
        is>>abonat_skype.id;
        is>>abonat_skype.nume;
        is>>abonat_skype.nr_telefon;
        is>>abonat_skype.id_skype;
        is>>abonat_skype.adresa_mail;
        return is;
    }
};
class Abonat_Skype_Extern:public Abonat_Skype{
protected:
    string tara;
public:
    Abonat_Skype_Extern():Abonat_Skype(){
        tara="EMPTY";
    }
    Abonat_Skype_Extern(int id, string nume, string nr_telefon, string id_skype, string tara):Abonat_Skype(id, nume, nr_telefon,id_skype),tara(tara){}
    string getTara(){
        return tara;
    }
    virtual ~Abonat_Skype_Extern(){}
    void setTara(string tara){
        this->tara=tara;
    }
    virtual ostream& print(ostream& os) const override {
        Abonat_Skype::print(os);
        os << tara << endl;
        return os;
    }
    Abonat_Skype_Extern* clone() const override {
        return new Abonat_Skype_Extern(*this);
    }
    friend ostream& operator<<(ostream& os, const Abonat_Skype_Extern& abonat){
        return abonat.print(os);
    }
    friend istream& operator>>(istream& is, Abonat_Skype_Extern& abonat_skype){
        is>>abonat_skype.id;
        is>>abonat_skype.nume;
        is>>abonat_skype.nr_telefon;
        is>>abonat_skype.id_skype;
        is>>abonat_skype.tara;
        return is;
    }
};
class Agenda{
    vector<Persoana*> agenda;
public:
    void AdaugaPersoana(Persoana *persoana){
        agenda.push_back(persoana);
    }
    void EliminaPersoana(Persoana *persoana){
        for(int i = 0; i < agenda.size(); i++) {
            if(agenda[i] == persoana) {
                delete agenda[i];
                agenda.erase(agenda.begin() + i);
                break;
            }
        }
    }
    void AfiseazaAgenda() {
        for(int i = 0; i < agenda.size(); i++) {
            cout << *agenda[i]<<endl;
        }
    }
    int size() {
        return agenda.size();
    }
    Persoana* operator[](const string& nume) {
        for(auto& persoana : agenda) {
            if(persoana->getNume() == nume) {
                return persoana;
            }
        }
        return nullptr;
    }
    Agenda& operator=(const Agenda& other) {
        agenda.clear();
        for (Persoana* persoana : other.agenda) {
            agenda.push_back(persoana->clone());
        }
        return *this;
    }
    Agenda(Agenda& other) {
        for (Persoana* persoana : other.agenda) {
            agenda.push_back(persoana->clone());
        }
    }
    ~Agenda() {
        for (int i = 0; i < agenda.size(); i++) {
            delete agenda[i];
        }
    }
    Agenda() {}


};
class meniuAgenda{
    Agenda agenda;
public:
    static const string ADD;
    static const std::string REMOVE;
    static const std::string DISPLAY_ALL;
    static const std::string TOTAL;
    static const std::string STOP;
    static const string COPY;
    static void DisplayMenuMessage(){
        cout<<ADD<<" - citeste si adauga o noua persoana"<<endl;
        cout<<REMOVE<<" - sterge persoana"<<endl;
        cout<<DISPLAY_ALL<<" - afiseaza toate persoanele"<<endl;
        cout<<TOTAL<<" - afiseaza numarul total de persoane"<<endl;
        cout<<STOP<<" - opreste programul"<<endl;
    };
    void RunMenu() {
        DisplayMenuMessage();
        string command;
        while (command != STOP) {
            cin>>command;
            if (command == ADD) {
                cout<<"Ce tip de persoana doriti sa adaugati?"<<endl;
                string persoana_tip;
                cin>>persoana_tip;
                cout<<"Introduceti datele persoanei"<<endl;
                if(persoana_tip=="Persoana"){
                    Persoana *persoana=new Persoana;
                    int id;
                    cout<<"Introduceti id-ul persoanei"<<endl;
                    cin>>id;
                    persoana->setId(id);
                    string nume;
                    cout<<"Introduceti numele persoanei"<<endl;
                    cin>>nume;
                    persoana->setNume(nume);
                    agenda.AdaugaPersoana(persoana);
                }
                else if(persoana_tip=="Abonat") {
                    Abonat *abonat=new Abonat;
                    int id;
                    cout<<"Introduceti id-ul persoanei"<<endl;
                    cin>>id;
                    abonat->setId(id);
                    string test;
                    cout<<"Introduceti numele persoanei"<<endl;
                    cin>>test;
                    abonat->setNume(test);
                    string tel;
                    cout<<"Introduceti numarul de telefon"<<endl;
                    cin>>tel;
                    abonat->setNr_Telefon(tel);
                    agenda.AdaugaPersoana(abonat);
                }
                else if(persoana_tip=="Abonat_Skype") {
                    Abonat_Skype *abonat = new Abonat_Skype;
                    int id;
                    cout<<"Introduceti id-ul persoanei"<<endl;
                    cin>>id;
                    abonat->setId(id);
                    string test;
                    cout<<"Introduceti numele persoanei"<<endl;
                    cin>>test;
                    abonat->setNume(test);
                    string tel;
                    cout<<"Introduceti numarul de telefon"<<endl;
                    cin>>tel;
                    abonat->setNr_Telefon(tel);
                    string id_skype;
                    cout<<"Introduceti id-ul de skype"<<endl;
                    cin>>id_skype;
                    abonat->setId_Skype(id_skype);
                    agenda.AdaugaPersoana(abonat);
                }
                else if(persoana_tip=="Abonat_Skype_Romania") {
                    Abonat_Skype_Romania *abonat=new Abonat_Skype_Romania;
                    int id;
                    cout<<"Introduceti id-ul persoanei"<<endl;
                    cin>>id;
                    abonat->setId(id);
                    string test;
                    cout<<"Introduceti numele persoanei"<<endl;
                    cin>>test;
                    abonat->setNume(test);
                    string tel;
                    cout<<"Introduceti numarul de telefon"<<endl;
                    cin>>tel;
                    abonat->setNr_Telefon(tel);
                    string id_skype;
                    cout<<"Introduceti id-ul de skype"<<endl;
                    cin>>id_skype;
                    abonat->setId_Skype(id_skype);
                    string mail;
                    cout<<"Introduceti adresa de mail"<<endl;
                    cin>>mail;
                    abonat->setAdresa_Mail(mail);
                    agenda.AdaugaPersoana(abonat);
                }
                else if(persoana_tip=="Abonat_Skype_Extern") {
                    Abonat_Skype_Extern *abonat = new Abonat_Skype_Extern;
                    int id;
                    cout<<"Introduceti id-ul persoanei"<<endl;
                    cin>>id;
                    abonat->setId(id);
                    string test;
                    cout<<"Introduceti numele persoanei"<<endl;
                    cin>>test;
                    abonat->setNume(test);
                    string tel;
                    cout<<"Introduceti numarul de telefon"<<endl;
                    cin>>tel;
                    abonat->setNr_Telefon(tel);
                    string id_skype;
                    cout<<"Introduceti id-ul de skype"<<endl;
                    cin>>id_skype;
                    abonat->setId_Skype(id_skype);
                    string tara;
                    cout<<"Introduceti tara"<<endl;
                    cin>>tara;
                    abonat->setTara(tara);
                    agenda.AdaugaPersoana(abonat);
                }
                else{
                    cout<<"Tip de persoana invalid"<<endl;
                }
            } else if (command == REMOVE) {
                cout<<"Introduceti numele persoanei pe care doriti sa o stergeti"<<endl;
                string nume;
                cin>>nume;
                if (agenda[nume] != nullptr) {
                    agenda.EliminaPersoana(agenda[nume]);
                } else {
                    cout << "Persoana nu exista" << endl;
                }
            } else if (command == DISPLAY_ALL) {
                agenda.AfiseazaAgenda();
            } else if (command == TOTAL) {
                cout << agenda.size();
            }else {
                cout << "Comanda invalida" << endl;
            }
        }

    }
    meniuAgenda();
};
class test{
public:
    void testEgalPersoana(){
        Persoana persoana(1234,"Test");
        Persoana persoana1;
        persoana1=persoana;
        cout<<persoana;
    }
    void testConstructorPersoana(){
        Persoana persoana;
        cout<<persoana;
    }
    void testSetGetPersoana(){
        Persoana persoana;
        persoana.setId(1234);
        persoana.setNume("TEST");
        cout<<persoana<<endl;
    }
    void testConstructorParametrizatPersoana(){
        Persoana persoana(1234,"Test parametrizat");
        cout<<persoana<<endl;
    }
    void testConstructorCopierePersoana(){
        Persoana persoana(1234,"Test copiere");
        Persoana persoana_copiata(persoana);
        cout<<persoana_copiata<<endl;
    }
    void testCinCoutPersoana(){
        Persoana persoana;
        cin>>persoana;
        cout<<persoana;
    }
    void testSetGetAbonat(){
        Abonat abonat ;
        Persoana* abonat1=new Abonat;
        if(Abonat * abonat2 = dynamic_cast<Abonat *>(abonat1)) {
            //pt info despre dynamic_cast: https://en.cppreference.com/w/cpp/language/dynamic_cast
            abonat2 ->setNr_Telefon("0777");
            abonat2->print(cout);
        }
        abonat.setId(1234);
        abonat.setNume("TEST");
        abonat.setNr_Telefon("Numar de telefon");
        cout<<*abonat1<<endl;
    }
    void testConstructorParametrizatAbonat(){
        Abonat abonat(1234,"Test parametrizat","Numar de telefon");
        cout<<abonat<<endl;
    }
    void testConstructorCopiereAbonat(){
        Abonat abonat(1234,"Test parametrizat","Numar de telefon");
        Abonat abonat_copiat(abonat);
        cout<<abonat_copiat<<endl;
    }
    void testCinCoutAbonat(){
        Abonat abonat;
        cin>>abonat;
        cout<<abonat;
    }
    void testSetGetAbonatSkype(){
        Abonat_Skype abonat;
        abonat.setId(1234);
        abonat.setNume("TEST");
        abonat.setNr_Telefon("Numar de telefon");
        abonat.setId_Skype("Id_skype");
        cout<<abonat<<endl;
    }
    void testConstructorParametrizatAbonatSkype(){
        Abonat_Skype abonat(1234,"Test parametrizat","Numar de telefon","Id skype");
        cout<<abonat<<endl;
    }
    void testConstructorCopiereAbonatSkype(){
        Abonat_Skype abonat(1234,"Test parametrizat","Numar de telefon","Id skype");
        Persoana abonat_copie(abonat);
        cout<<abonat_copie<<endl;
    }
    void testCinCoutAbonatSkype(){
        Abonat_Skype abonatSkype;
        cin>>abonatSkype;
        cout<<abonatSkype;
    }
    void testSetGetAbonatSkypeRomania(){
        Abonat_Skype_Romania abonat;
        abonat.setId(1234);
        abonat.setNume("TEST");
        abonat.setNr_Telefon("Numar de telefon");
        abonat.setId_Skype("Id skype");
        abonat.setAdresa_Mail("Adresa mail");
        cout<<abonat<<endl;
    }
    void testConstructorParametrizatAbonatSkypeRomania(){
        Abonat_Skype_Romania abonat(1234,"Test parametrizat","Numar de telefon","Id skype","Adresa mail");
        cout<<abonat<<endl;
    }
    void testConstructorCopiereAbonatSkypeRomania(){
        Abonat_Skype_Romania abonat(1234,"Test parametrizat","Numar de telefon","Id skype","Adresa mail");
        Abonat_Skype_Romania abonat_copie(abonat);
        cout<<abonat_copie<<endl;
    }
    void testCinCoutAbonatSkypeRomania(){
        Abonat_Skype_Romania abonat(1234,"Test parametrizat","Numar de telefon","Id skype","Adresa mail");
        cin>>abonat;
        cout<<abonat;
    }
    void testSetGetAbonatSkypeExtern(){
        Abonat_Skype_Extern abonat;
        abonat.setId(1234);
        abonat.setNume("TEST");
        abonat.setNr_Telefon("Numar de telefon");
        abonat.setId_Skype("Id skype");
        abonat.setTara("Tara");
        cout<<abonat<<endl;
    }
    void testConstructorAbonatSkypeExtern(){
        Abonat_Skype_Extern abonat(1234,"Test parametrizat","Numar de telefon","Id skype","Tara");
        cout<<abonat<<endl;
    }
    void testConstructorCopiereAbonatSkypeExtern(){
        Abonat_Skype_Extern abonat(1234,"Test parametrizat","Numar de telefon","Id skype","Tara");
        Persoana abonat_copiat(abonat);
        cout<<abonat_copiat<<endl;
    }
    void testCinCoutAbonatSkypeExtern(){
        Abonat_Skype_Extern abonat;
        cin>>abonat;
        cout<<abonat;
    }
    void testAdaugaPersoana(){
        Agenda agenda;
        Persoana persoana(1234,"Test");
        agenda.AdaugaPersoana(&persoana);
        agenda.AfiseazaAgenda();
    }
    void testEliminaPersoana(){
        Agenda agenda;
        Persoana persoana(1234,"Test");
        agenda.AdaugaPersoana(&persoana);
        agenda.EliminaPersoana(&persoana);
        agenda.AfiseazaAgenda();
    }
    void testOperatorIndex(){
        Agenda agenda;
        Persoana persoana(1234,"Test");
        agenda.AdaugaPersoana(&persoana);
        cout<<*agenda["Test"];
    }
    void testSize(){
        Agenda agenda;
        Persoana persoana(1234,"Test");
        agenda.AdaugaPersoana(&persoana);
        cout<<agenda.size();
    }
    void testEgalAgenda(){
        Agenda agenda;
        cout<<"Se v-a copia intr-o noua agenda"<<endl;
        Abonat* abonat=new Abonat(1234,"Test","Numar de telefon");
        Persoana* persoana=new Persoana(1234,"Test");
        agenda.AdaugaPersoana(abonat);
        agenda.AdaugaPersoana(persoana);
        Agenda agenda1;
        agenda1=agenda;
        agenda1.AfiseazaAgenda();
    }
    void testConstructorCopiereAgenda(){
        cout<<"Se v-a construi o copie intr-o noua agenda"<<endl;
        Agenda agenda;
        Abonat* abonat=new Abonat(1234,"Test","Numar de telefon");
        Persoana* persoana=new Persoana(1234,"Test");
        agenda.AdaugaPersoana(abonat);
        agenda.AdaugaPersoana(persoana);
        Agenda agenda1(agenda);
        agenda1.AfiseazaAgenda();
    }
};
const string meniuAgenda::ADD = "ADD";
const string meniuAgenda::REMOVE = "REMOVE";
const string meniuAgenda::DISPLAY_ALL = "DISPLAY_ALL";
const string meniuAgenda::TOTAL = "TOTAL";
const string meniuAgenda::STOP = "STOP";
const string meniuAgenda::COPY = "COPY";

meniuAgenda::meniuAgenda() {
    agenda = Agenda();
}

int main(){
    test test;
//    test.testEgalPersoana();
//    test.testConstructorPersoana();
//    test.testSetGetPersoana();
//    test.testConstructorParametrizatPersoana();
//    test.testConstructorCopierePersoana();
//    test.testCinCoutPersoana();
    test.testSetGetAbonat();
//    test.testConstructorParametrizatAbonat();
//    test.testConstructorCopiereAbonat();
//    test.testCinCoutAbonat();
//    test.testSetGetAbonatSkype();
//    test.testConstructorParametrizatAbonatSkype();
//    test.testConstructorCopiereAbonatSkype();
//    test.testCinCoutAbonatSkype();
//    test.testSetGetAbonatSkypeRomania();
//    test.testConstructorParametrizatAbonatSkypeRomania();
//    test.testConstructorCopiereAbonatSkypeRomania();
//    test.testCinCoutAbonatSkypeRomania();
//    test.testSetGetAbonatSkypeExtern();
//    test.testConstructorAbonatSkypeExtern();
//    test.testConstructorCopiereAbonatSkypeExtern();
//    test.testCinCoutAbonatSkypeExtern();
//    test.testAdaugaPersoana();
//    test.testEliminaPersoana();
//    test.testOperatorIndex();
//    test.testSize();
//    test.testEgalAgenda();
//    test.testConstructorCopiereAgenda();
//    meniuAgenda meniu;
//    meniu.RunMenu();
//    return 0;
}