#include <iostream>

class Contact {
    private:
        // Data members (attributes)
        std::string name;
        long number;
        
	public:
        // Member functions (methods)
        Contact() : name(""), number(0) {}

		void new_contact(std::string new_name, long num)
		{
			name = new_name;
			number = num;
		}

		void clear()
		{
			name = "";
			number = 0;
		}

		void display()
		{
			std::cout << "Contact Name: " << name;

		}
};


// class PhoneBook {
//     private:
//         // Data members (attributes)
//         DataType memberName;
        
// 	public:
//         // Member functions (methods)
//         ReturnType functionName(parameters);
// };


