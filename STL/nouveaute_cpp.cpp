#include <iostream>
#include <memory>


class Contact {
protected:
    std::string name;
    std::string mail;
public:
    Contact(std::string name, std::string mail): name(name), mail(mail) { };
    ~Contact(){};

    void display() {
        std::cout << "Nom : \t\t" << name <<  std::endl;
        std::cout << "e-mail : \t" << mail <<  std::endl;
    }

    void mail_update(std::string new_mail) {
        mail = new_mail;
    }
};


/*
Créez une fonction qui prend un std::shared_ptr<Contact> en paramètre et modifie le mail du
contact.
*/
void update_mail(std::shared_ptr<Contact> shared_ptr_contact, std::string new_mail) {
    shared_ptr_contact->mail_update(new_mail);
}

int main() {
    /*
    Créez ensuite un contact et utilisez un smart pointer pour lui allouer un espace mémoire.
    Créez une fonction qui prend un pointeur std::unique_ptr<Contact> en paramètre
    et affiche les détails du contact.
    */
   Contact contact("Moi", "moi@mon_mail.com");

   contact.display();

    std::unique_ptr<Contact> uniquePtrContact = std::make_unique<Contact>(contact);

    std::cout << "Changement de mail directement par unique_ptr" <<  std::endl;
    uniquePtrContact->mail_update("un_nouveau@mail.com");
    uniquePtrContact->display();

    std::cout <<  std::endl << "Changement de mail par fonction avec un shared_ptr en paramètre" <<  std::endl;
    std::shared_ptr<Contact> shared_ptr_contact_1 = std::make_shared<Contact>(contact);
    update_mail(shared_ptr_contact_1, "encore_un@mail.net");
    shared_ptr_contact_1->display();

    std::cout <<  std::endl << "Affichage via uniquePtrContact" <<  std::endl;
    uniquePtrContact->display();

    /*
    Créez plusieurs std::shared_ptr pour le même contact et observez le comportement de la
    gestion de la mémoire. Que constatez ?
    */
    std::shared_ptr<Contact> shared_ptr_contact_2 (&contact);
    shared_ptr_contact_2->mail_update("shared_ptr_contact_2");
    shared_ptr_contact_2->display();
    std::shared_ptr<Contact> shared_ptr_contact_3 = shared_ptr_contact_2;
    shared_ptr_contact_3->mail_update("shared_ptr_contact_3");
    shared_ptr_contact_3->display();
    std::shared_ptr<Contact> shared_ptr_contact_4 = std::make_shared<Contact>(contact);
    shared_ptr_contact_4->mail_update("shared_ptr_contact_4");
    shared_ptr_contact_4->display();
    std::cout <<  std::endl << "Affichage du shared_ptr_contact_2" <<  std::endl;
    shared_ptr_contact_2->display();
    std::cout <<  std::endl << "Affichage du contact" <<  std::endl;
    contact.display();

    std::cout <<  std::endl << "Nombre de SharePointer : " << shared_ptr_contact_2.use_count() <<  std::endl;


    return 0;
}
