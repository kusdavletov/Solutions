const int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int thirdLargestIndex(int a[], int len){
    int first = a[0], second = INT_MIN, third = INT_MIN;
    int first_index = 0, second_index = 0, third_index = 0;
    for (int i = 1; i < len; i++){
        if (a[i] > first){
            third = second;
            third_index = second_index;
            second = first;
            second_index = first_index;
            first  = a[i];
            first_index = i;
        }
        else if (a[i] > second && a[i] != first)
        {
            third = second;
            third_index = second_index;
            second = a[i];
            second_index = i;
        }
         else if (a[i] > third && a[i] != first && a[i] != second)
            third = a[i];
            third_index = i;
    }
    return third_index;
}

int leapYears(Date date){
    int years = date.Year;
    if (date.Month <= 2)
        years -= 1;
    return years / 4 + years / 400 - years / 100;
}

Date ThirdLatest(std::vector<Date> & dates) {
    int temp, index_third;
    int dates_size = dates.size();
    int arr[dates_size];
    for (int i = 0; i < dates_size; i++){
        temp = dates[i].Year * 365 + dates[i].Day;
        for (int j = 0; j < dates[i].Month - 1; j++)
            temp += daysInMonths[i];
        temp += leapYears(dates[i]);
        arr[i] = temp;
    }
    index_third = thirdLargestIndex(arr, dates_size);
    return dates[index_third - 1];
}
