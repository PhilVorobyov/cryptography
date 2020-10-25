
#include<gmp.h>
#include <cstdio>

class GmpGcd {
public:
    void gcdGMP(int n1, int n1_power, int n2, int n2_power) {
        mpz_t r1; mpz_init(r1);
        mpz_t r2; mpz_init(r2);
        mpz_t r1_power; mpz_init(r1_power);
        mpz_t r2_power; mpz_init(r2_power);

        mpz_set_ui(r1, n1);
        mpz_set_ui(r1_power, n1_power);
        mpz_set_ui(r2, n2);
        mpz_set_ui(r2_power, n2_power);

        mpz_out_str(stdout, 10, r1);
        printf(" power:  ");
        mpz_out_str(stdout, 10, r1_power);
        printf("\n");
        mpz_out_str(stdout, 10, r2);
        printf(" power:  ");
        mpz_out_str(stdout, 10, r2_power);
        printf("\n");

        // power r1
        mpz_t r1_rop; mpz_init(r1_rop);
        mpz_pow_ui(r1_rop, r1, n1_power);
        gmp_fprintf(stdout, "%Zd\n", r1_rop);

        // power r2
        mpz_t r2_rop; mpz_init(r2_rop);
        mpz_pow_ui(r2_rop, r2, n2_power);
        gmp_fprintf(stdout, "%Zd\n", r2_rop);
        printf("\n");

        printf("Build in GCD: ");
        mpz_t result; mpz_init(result);
        mpz_gcd(result, r1_rop, r2_rop);
        gmp_fprintf(stdout, "%Zd\n", result);
        printf("\n");

        printf("GCD: ");
        mpz_t r1_r; mpz_init(r1_r);
        mpz_cdiv_r(r1_r, r1_rop, r2_rop);

        mpz_t zero; mpz_init(zero);
        if (mpz_cmp(zero, r1_r) == 0) {
            gmp_fprintf(stdout, "%Zd\n", r2_rop);
        } else {
            gcd(r2_rop, r1_r);
        }
    }

    void gcd(mpz_t p, mpz_t r) {
        mpz_t r1; mpz_init(r1);
        mpz_cdiv_r(r1, p, r);

        mpz_t zero; mpz_init(zero);
        mpz_t r1_zero_check; mpz_init(r1_zero_check); mpz_set_ui(r1_zero_check, 0);
        mpz_cdiv_r(r1_zero_check, r, r1);

        if (mpz_cmp(zero, r1_zero_check) == 0) {
            gmp_fprintf(stdout, "%Zd\n", r1);
            mpz_out_str(stdout, 10, r1);
        } else {
            return this -> gcd(r, r1);
        }
    }
};

int main (){
    GmpGcd a;
    a.gcdGMP(2, 4096, 2, 256);
}


