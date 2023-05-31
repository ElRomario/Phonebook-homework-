/*Создайте приложение "Телефонная книга". Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего класса. Наполните класс переменными-членами, функциями-членами, конструкторами, inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память
под ФИО. Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов, искать абонентов по ФИО, показывать всех абонентов, сохранять
информацию в файл и загружать из файла.*/

#include <iostream>
using namespace std;

class Contact
{
private:
    string name;
    string homeNumber;
    string mobileNumber;
    string extraInfo;
public:

    Contact(string nameP, string homeN, string mobileN, string extra) : name{ nameP }, homeNumber{ homeN }, mobileNumber{ mobileN }, extraInfo{ extra }{};
  
    //Contact() : Contact{ "unknown", "unknown", "unknown","unknown" }{}
    
    Contact() : Contact{ "", "", "","" } {};
   
   
    string getName()
    {
        return name;
    }
    void setContact()
    {
        cout << "Enter name:" << endl;
        cin >> name;

        cout << "Enter home number:" << endl;
        cin >> homeNumber;

        cout << "Enter mobile number:" << endl;
        cin >> mobileNumber;

        cout << "Enter extra info:" << endl;
        cin >> extraInfo;
    }
    void inline printContact()
    {
        cout << "Name: " << name << endl << "Home Number:" << homeNumber << endl << "Moblile Number:" << mobileNumber << endl << "Extra Info:" << extraInfo << endl;
    }
    ~Contact() 
    { };
};
void addContact(Contact*& phoneBook, int& contactBookSize)
{
    cout << "###############################" << endl;
    cout << "####--Adding new contact!--####" << endl;
    cout << "###############################" << endl;
    Contact* newPhoneBook = new Contact[contactBookSize+1];
    Contact newContact; newContact.setContact();
    for (int i = 0; i < contactBookSize; i++)
    {
        newPhoneBook[i] = phoneBook[i];
    }
    newPhoneBook[contactBookSize] = newContact;
    delete[] phoneBook;
    phoneBook = newPhoneBook;
    contactBookSize++;
    
}
Contact searchContact(Contact* phoneBook, string name, int phoneBookSize)
{
    for (int i = 0; i < phoneBookSize; i++)
    {
        if (phoneBook[i].getName() == name)
        {
            return phoneBook[i];
            break;
        }
        
    }
}
void deleteContact(Contact*& phoneBook, int& contactBookSize, int index)
{
    if (index < 0 || index >= contactBookSize) {
        cout << "Invalid index!" << endl;
        return;
    }
    cout << "Deleting contact!" << endl;
    for (int i = index; i < contactBookSize - 1; i++) // сдвиагаем элементы влево начиная с удаляемого элемента(перезаписываем его)
    {
        phoneBook[i] = phoneBook[i + 1];
    }
    contactBookSize--;
    Contact* newPhoneBook = new Contact[contactBookSize];
    for (int i = 0; i < contactBookSize; i++) 
    {
        newPhoneBook[i] = phoneBook[i];
    }
    delete[] phoneBook;
    phoneBook = newPhoneBook;
}

//void deleteContact(Contact*& phoneBook, int& contactBookSize, string deletedName)
//{
//
//  /*  for (int i = 0, j = 0; i < size - 1; i++)
//    {
//        if (i != index)
//        {
//            newMenArray[j++] = (*menArray)[i];
//        }
//    }*/
//    
//    Contact* newPhoneBook = new Contact[contactBookSize - 1];
//    cout << "#############################" << endl;
//    cout << "####--Deleting contact!--####" << endl;
//    cout << "#############################" << endl;
//    for (int i = 0, g = 0; i < contactBookSize - 1; i++)
//    {
//        if (deletedName != phoneBook[i].getName())
//        newPhoneBook[g++] = phoneBook[i];
//    }
//    delete[] phoneBook;
//    phoneBook = newPhoneBook;
//    contactBookSize--;
//}
void printContactBook(Contact* phoneBook, int phonebookSize)
{
    cout << "#############################" << endl;
    cout << "######--All contacts--#######" << endl;
    cout << "#############################" << endl;
    for (int i = 0; i < phonebookSize; i++)
    {
       
        phoneBook[i].printContact();
        cout << "#############################"<<endl;
    }
}

int main()
{
   /* Contact sergey;
    sergey.printContact();*/
    int contactBookSize = 2;
    Contact* phoneBook = new Contact[contactBookSize]{Contact("Ivan", "89242330833","228282828", "friend"), Contact("Peter","28288282","8282828282","Cousin")};

    printContactBook(phoneBook, contactBookSize);
    addContact(phoneBook, contactBookSize);
    printContactBook(phoneBook, contactBookSize);
    deleteContact(phoneBook, contactBookSize, 2);
    printContactBook(phoneBook, contactBookSize);

}

