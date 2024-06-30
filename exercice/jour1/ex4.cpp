#include <iostream>
#include <vector>

class Worker {
public:
    virtual ~Worker() {}
    virtual void work() const = 0;
};

class Person {
protected:
    std::string firstname;
    std::string lastname;
    int birthYear;

public:
    Person(std::string fn, std::string ln, int year) : firstname(fn), lastname(ln), birthYear(year) { }
};

class Student : virtual public Person, public Worker {
protected:
    int numero;
    std::string specialisation;
    std::vector<float> marks;

public:
    Student(std::string fn, std::string ln, int year, int num, std::string spec) : Person(fn, ln, year) {
        numero = num;
        specialisation = spec;
    }

    float calcAverageMark() {
        float average = 0;
        for (const auto& mark: marks) {
            average += mark;
        }
        return average / marks.size();
    }

    void work() const override {
        std::cout << "Etudiant travaille" << std::endl;
    }
};

class Teacher : public Person, public Worker {
protected:
    std::string subject;

public:
    Teacher(std::string fn, std::string ln, int year, std::string sub) : Person(fn, ln, year) {
        subject = sub;
    }

    void work() const override {
        std::cout << "Enseignant travaille" << std::endl;
    }
};

class AdminEmploye : virtual public Person, public Worker {
protected:
    int numero;
    std::string position;

public:
    AdminEmploye(std::string fn, std::string ln, int year, int num, std::string pos) : Person(fn, ln, year) {
        numero = num;
        position = pos;
    }

    void work() const override {
        std::cout << "Employe administratif travaille" << std::endl;
    }
};


class StudentWorker : public Student, public AdminEmploye {
public:
    StudentWorker(std::string fn, std::string ln, int year, int numStudent, std::string spec, int numEmploye, std::string position) :
    Student(fn, ln, year, numStudent, spec), AdminEmploye(fn, ln, year, numEmploye, position), Person(fn, ln, year) { }

    void work() const override {
        std::cout << "Etudiant employe travaille" << std::endl;
    }

    void introduce() const {
        std::cout << "Bonjour je suis " << firstname << " " << lastname << ". Je suis né en " << birthYear << " et je suis l'étudiant numero " << Student::numero << " specialise en " << specialisation << " et en " << position << " avec le numero d'employe de " << AdminEmploye::numero << "." << std::endl;
    }
};

int main() {
    StudentWorker john("John", "Doe", 1980, 123, "informatique", 456, "stagiaire imprimante-cafe");

    john.work();
    john.introduce();
    return 0;
}