typedef struct {
    unsigned int first_visit:1; // can store true/false
    unsigned int come_again:1;
    unsigned int fingers_lost:4; // is needed to store a number up to 10
    unsigned int shark_attack:1;
    unsigned int days_a_week:3; // 3 bits can store numbers up to 7
}
