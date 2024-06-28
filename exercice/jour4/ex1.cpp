#include <iostream>
#include <memory>

class Contact {
private:
    std::string name;
    std::string mail;

public:
    Contact(const std::string& n, const std::string& m) : name(n), mail(m) { }

    void modifyMail(const std::string& newMail) {
        mail = newMail;
    }

    void display() const {
        std::cout << " Contact : " << name << ", mail : " << mail << std::endl;
    }
};

void displayContact(const std::unique_ptr<Contact>& contact) {
    contact->display();
}

void modifyContact(const std::shared_ptr<Contact>& contact, const std::string& newMail) {
    if (contact) {
        contact->modifyMail(newMail);
    }
}

int main() {
    std::unique_ptr<Contact> uniqueContact = std::make_unique<Contact>("John Doe", "john.doe@mail.com");
    displayContact(uniqueContact);

    std::shared_ptr<Contact> sharedContact1 = std::make_shared<Contact>("Melusine Enfaillite", "melusine.enfaillite@mail.com");
    std::shared_ptr<Contact> sharedContact2 = sharedContact1;
    std::shared_ptr<Contact> sharedContact3 = sharedContact1;
 
    sharedContact1->display();
    sharedContact2->display();
    sharedContact3->display();

    modifyContact(sharedContact1, "m.enfaillite@gmail.com");

    sharedContact1->display();
    sharedContact2->display();
    sharedContact3->display();

    return 0;
}