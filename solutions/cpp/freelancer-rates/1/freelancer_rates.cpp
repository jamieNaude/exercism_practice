
double daily_rate(double hourly_rate) {
    return 8*hourly_rate;
}

double apply_discount(double before_discount, double discount) {
    return before_discount*(1-discount/100);
}


int monthly_rate(double hourly_rate, double discount) {
    double val1 = (apply_discount(22*daily_rate(hourly_rate), discount));
    int val2 = (int)val1;
    if (val1 > (double)val2) {
        return val2+1;
    }
    return val2;
}


int days_in_budget(int budget, double hourly_rate, double discount) {
    return 22*budget/monthly_rate(hourly_rate, discount);
}
