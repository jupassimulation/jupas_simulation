distribution1: a vector n[1...20] where n[i] = the number of students who are accepted by their ith choice
distribution2: a tensor of a[1...20][1...11] the original ranking of 1st, 10th, 20th, 30th, 40th, 50th, 60th, 70th, 80th, 90th, 100th students accepted by each department.

run AB:
A represents the policy that the 1st department would deploy.
    1: no policy.
    2: only students who put it on 1st choice.
    3: only students who put it on 1st or 2nd choices.
    4: only students who put it on 1st, 2nd or 3rd choice.
    5: all students who do not put it on 1st choice will be move 50 down on its preference list
B represents the preference distribution
    1: all depts are equally likely to be selected
    2: the first 10 departments are twice like to be selected

eg. 42_distribution1.csv represents the vector of numbers of students who are accepted by their ith choice where the 1st dept only accept students who put it on 1st, 2nd or 3rd choice and the first 10 departments are twice like to be selected by students.
