#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> scores;
    for (int i = 0; i < student_scores.size(); i++) {
       scores.push_back(static_cast<int>(student_scores[i])); 
    } 
    return scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int num_fails{0};
    for (int i = 0; i < student_scores.size(); i++) {
       if (student_scores[i] <= 40) {
           num_fails++;
       }
    } 
    return num_fails;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int increment = (highest_score - 40)/4;
    std::array<int, 4> letters;
    for (int i = 0; i < 4; i++) {
        letters[i] = 41+increment*i;
    }
    return letters;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> rank;
    for (int i = 0; i < student_scores.size(); i++) {
        rank.push_back(std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    }
    return rank;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    for (int i = 0; i < student_scores.size(); i++) {
        if (student_scores[i] == 100) {
            return student_names[i];
        }
    }
    return "";
}
