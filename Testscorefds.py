class TestScores:
    def __init__(self):
        self.scores = []

    def get_data(self, n):
        print("Enter the Marks scored in FDS:")
        for i in range(n):
            self.scores.append(int(input(f"Enter marks of student {i + 1}:")))

    def compute_average(self):
        total = sum(self.scores)
        average = total / len(self.scores)
        return average
    
    def highest_and_lowest_scores(self):
        if not self.scores:
            return None, None
        highest_score = max(self.scores)
        lowest_score = min(self.scores)
        return highest_score, lowest_score
    
    def mark_with_highest_frequency(self):
        if not self.scores:
            return None
        
        marks_count = {}
        for mark in self.scores:
            if mark != -1:
                marks_count[mark] = marks_count.get(mark, 0) + 1

        max_count = max(marks_count.values(),default=0)
        max_marks = [mark for mark, count in marks_count.items() if count == max_count]

        return max_marks[0] if max_marks else None
    
    def count_absent_students(self):
        absent_count = self.scores.count(-1)
        return absent_count
    
def main():
    test_scores = TestScores()

    n = int(input("Enter the number of students in the class:"))

    test_scores.get_data(n)

    average = test_scores.compute_average()
    print(f"The average score of the class is: {round(average, 2)}")

    highest, lowest = test_scores.highest_and_lowest_scores()
    print(f"Highest score in the class: {highest}")
    print(f"Lowest score of the class {lowest}")

    absent_count = test_scores.count_absent_students()
    print(f"Number of student absent for the test: {absent_count}")

    max_frequency_mark = test_scores.mark_with_highest_frequency()
    print(f"marks with the higest frequency:  {max_frequency_mark}")

if __name__ == "__main__":
    main()