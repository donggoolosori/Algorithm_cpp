#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int score;
    Student(const string name, int score)
    {
        this->name = name;
        this->score = score;
    }
    // 정렬 기준은 점수가 작은 순서
    bool operator<(Student &student)
    {
        return this->score < student.score;
    }
};
int main()
{
    Student students[] = {
        Student("fdas", 100),
        Student("fdafda", 93),
        Student("fdaq", 98)};
    sort(students, students + 3);
    for (int i = 0; i < 3; i++)
    {
        cout << students[i].name << "\n";
    }
}