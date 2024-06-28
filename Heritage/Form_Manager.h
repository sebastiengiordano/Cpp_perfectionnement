#include <vector>

#include "Form.h"


class FormManager {
public:
    FormManager () = default;
    FormManager (Shape* shape[], int shape_list_size);
    virtual ~FormManager() {};

    void Add_form(Shape* shape);
    void calcAllArea();

protected:
    std::vector<Shape*> shape_list;
};
