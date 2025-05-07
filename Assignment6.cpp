#include <bits/stdc++.h>
using namespace std;

// class Evaluation {
// private:
//     string name;
//     map<string, pair<int, int>> competencies;
//     map<string, pair<int, int>> performance;

// public:
//     Evaluation() {
//         cout << "Enter name of employee: ";
//         getline(cin, name);

//         for (const string& c : {"Communication", "Productivity", "Creativity", "Integrity", "Punctuality"})
//             competencies[c] = {0, 0};

//         for (const string& g : {"Goal 1", "Goal 2", "Goal 3", "Goal 4", "Goal 5"})
//             performance[g] = {0, 0};
//     }

//     void getInput(map<string, pair<int, int>>& section, int& remaining) {
//         for (auto& [key, val] : section) {
//             cout << "Rating (1–3) for " << key << ": ";
//             cin >> val.first;
//             cout << "Weightage (remaining " << remaining << "): ";
//             cin >> val.second;
//             remaining -= val.second;
//         }
//     }

//     double calculateAndPrint(const map<string, pair<int, int>>& section, const string& title) {
//         cout << "\n" << title << "\n";
//         cout << "Category\t\tRating\tWeightage\tWeighted Score\n";
//         double sum = 0;
//         for (auto& [key, val] : section) {
//             double score = (val.first * val.second) / 100.0;
//             sum += score;
//             cout << left << setw(16) << key << "\t" << val.first << "\t" << val.second << "\t\t" << fixed << setprecision(2) << score << endl;
//         }
//         cout << "Total Weighted Score: " << fixed << setprecision(2) << sum << "\n";
//         return sum;
//     }

//     void evaluate() {
//         int remaining = 100;
//         cout << "\n--- Enter Competency Ratings ---\n";
//         getInput(competencies, remaining);

//         cout << "\n--- Enter Performance Ratings ---\n";
//         getInput(performance, remaining);

//         double compScore = calculateAndPrint(competencies, "Competency Goals");
//         double perfScore = calculateAndPrint(performance, "Performance Goals");

//         double total = compScore + perfScore;
//         cout << "\nOverall Rating of " << name << " (out of 3): " << fixed << setprecision(2) << total << endl;

//         cout << "Performance: ";
//         if (total >= 2.7)
//             cout << "Exceeds Expectations\n";
//         else if (total >= 1.7)
//             cout << "Meets Expectations\n";
//         else
//             cout << "Fails Expectations\n";
//     }
// };

// int main() {
//     Evaluation e;
//     e.evaluate();
//     return 0;
// }



class Evaluate{
    private:
    string name;
    map<string, pair<double, double>> comp;
   map<string, pair<double, double>> perf;


    public:

    Evaluate(){
        cout<<"Enter the name : ";
        cin.ignore();
        getline(cin, name);

        comp = {
            {"communication", {0.0, 0.0}},
            {"productivity", {0.0, 0.0}},
            {"creativity", {0.0, 0.0}},
            {"integrity", {0.0, 0.0}},
            {"puncuation", {0.0, 0.0}},

        };

        perf = {
            {"goal1", {0.0, 0.0}},
            {"goal2", {0.0, 0.0}},
            {"goal3", {0.0, 0.0}},
            {"goal4", {0.0, 0.0}},
            {"goal5", {0.0, 0.0}},

        };
    }


    void getInput( map<string, pair<double, double>> &mp, int & remain){
        for(auto & it : mp){
            cout<<"Enter the rating for "<<it.first<<" between (1-5) :  ";
            cin>>it.second.first;
            cout<<"Enter the weightage for "<<it.first<<" remaining ( "<<remain<<" ) :";
            cin>>it.second.second;
            remain -= it.second.second;

        }
    }


    double Calculate(map<string, pair<double, double>> &mp, string title){
        cout<<title<<endl;
        double sum = 0;
        cout<< "Category\t\trating\tWeightage\tScore"<<endl;
        for(auto it : mp){
            double temp = (it.second.first*it.second.second)/100;
            cout<<it.first<<"\t\t"<<it.second.first<<"\t"<<it.second.second<<"\t"<<temp<<endl;
            sum += temp;
        }

        return sum;
    }


    void Final(){
        int remain = 100;
        cout << "\n--- Enter Competency Ratings ---\n";
        getInput(comp, remain);
        cout << "\n--- Enter Performance Ratings ---\n";
        remain = 100;
        getInput(perf, remain);

        double sum1 = Calculate(comp, "Competency");
        double sum2 = Calculate(perf, "Performance");

         double total = sum1 + sum2;

         cout<<"Overall Rating of "<<name<<" is "<<total<<endl;

         cout << "Performance: ";
        if (total >= 8.5)
            cout << "Exceeds Expectations\n";
        else if (total >= 7)
            cout << "Meets Expectations\n";
        else
            cout << "Fails Expectations\n";
    }
};




int main(){
  

    Evaluate e;
    e.Final();

    return 0;
}