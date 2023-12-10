class Test:
    def __init__(self):
        self.fds = []
        self.n = 0

    def getdata(self):
        self.n = int(input('\nEnter the class strength of SE Comp A: '))
        print('\n(Note: Enter -1 for absent students)\n')
        print('---------------------------------------------------------')
        print('Enter the marks scored in Fundamental of Data Structure: ')
        print('---------------------------------------------------------\n\n')
        for i in range(self.n):
            self.fds.append(int(input(f'Enter marks of roll no {i + 1}: ')))

    def putdata(self):
        print('\n\nTest Marks of Fundamental of Data Structure are as follows...\n')
        print('*********************************')
        print('| Roll No | DSA Marks |')
        print('*********************************')
        for i in range(self.n):
            print(f'|\t{i + 1}\t|\t{self.fds[i]}\t|')
        print('---------------------------------\n\n')

    def avg(self):
        total = 0
        present = 0
        for i in self.fds:
            if i != -1:
                total += i
                present += 1
        if present > 0:
            print(f'Average marks of the class: {round(total / present, 3)}\n\n')
        else:
            print('No students present to calculate the average.\n\n')

    def absstud(self):
        print('Students absent for Fundamental of Data Structure test are: \n')
        absent = 0
        for i in range(self.n):
            if self.fds[i] == -1:
                print(f'Roll No: {i + 1} absent')
                absent += 1
        print(f'\nTotal absent students are: {absent}\n\n')

    def maxmin(self):
        maxi, max_rollno, mini, min_rollno = float('-inf'), [], float('inf'), []
        for i, val in enumerate(self.fds):
            if val != -1:
                if maxi == val:
                    max_rollno.append(i + 1)
                elif maxi < val:
                    max_rollno = [i + 1]
                    maxi = val
                if mini == val:
                    min_rollno.append(i + 1)
                elif mini >= val:
                    min_rollno = [i + 1]
                    mini = val
        max_rollno, min_rollno = ', '.join(map(str, max_rollno)), ', '.join(map(str, min_rollno))
        if maxi != float('-inf'):
            print(f'Highest Test Score : Roll No : ({max_rollno}) with Marks = {maxi}\n')
        else:
            print('No scores available to determine the highest.\n')
        if mini != float('inf'):
            print(f'Lowest Test Score : Roll No : ({min_rollno}) with Marks = {mini}\n')
        else:
            print('No scores available to determine the lowest.\n')

    def frequency(self):
        marks_count = {}
        for val in self.fds:
            if val != -1:
                marks_count[val] = marks_count.get(val, 0) + 1

        max_count = max(marks_count.values(), default=0)
        max_marks = [mark for mark, count in marks_count.items() if count == max_count]

        if max_count != 0:
            max_marks_str = ', '.join(map(str, max_marks))
            print(f'Marks {max_marks_str} occurred maximum times ({max_count}) in the records.')
        else:
            print('No scores available to determine the maximum frequency.\n')

def main():
    test = Test()
    test.getdata()
    test.putdata()
    test.avg()
    test.absstud()
    test.maxmin()
    test.frequency()


if __name__ == "__main__":
    main()
