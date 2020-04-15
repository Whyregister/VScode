#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <algorithm>
using namespace std;
class Student
{

        private:
                string m_name;
                string m_des;
                int m_age;
                int m_ScoreCount;
                float * m_Scores;
                        
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

                void AddScore(float newscore);
                float GetScoreTal();
                Student scholar(Student & stu);
                void InitInfor();
        protected:



};

#endif // STUDENT_H