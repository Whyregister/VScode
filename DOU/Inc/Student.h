#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
class Student
{

        private:
                string m_name;
                string m_des;
                int m_age;
                        
        public:
                Student();
                Student(string Name);
                Student(string Name,string Des);

                ~Student();

                void SetName(string);
                string ShowName();

                void SetDes(string);
                string ShowDes();

                void ShowInfor();
        protected:



};

#endif // STUDENT_H