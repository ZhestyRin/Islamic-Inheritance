#include <stdio.h>
#include <stdbool.h>

#define IS_TRUE(x) ((x) >= 1)
#define IS_FALSE(x) ((x) == 0)

typedef struct {
    int Children[2];
    int Parents2[2];
    int Spouse[2];
    int GrandchildrenFromSon[2];
    int Brothers[3];
    int Sisters[3];
    int Grandparents[2];
    double Inheritance;
    float Ashabah;
    float KShabah;
} Family;


void InputInheritance(Family *dt) {
    printf("Enter total inheritance amount:\n");
    scanf(" %lf", &dt->Inheritance);
}


void InputChildren(Family *dt) {
    printf("Is there a son? Enter '0' for no, '1' for yes\n");
    scanf(" %d", &dt->Children[0]);

    printf("How many daughters? Enter '0' if none, or the number if any\n");
    scanf(" %d", &dt->Children[1]);
}


void InputParents2(Family *dt) {
    printf("Is the father alive? Enter '0' for no, '1' for yes\n");
    scanf(" %d", &dt->Parents2[0]);

    printf("Is the mother alive? Enter '0' for no, '1' for yes\n");
    scanf(" %d", &dt->Parents2[1]);
}


void InputSpouse(Family *dt) {
    printf("Is there a husband? Enter '0' for no, '1' for yes\n");
    scanf("%d", &dt->Spouse[0]);

    printf("Is there a wife? Enter '0' for no, '1' for yes\n");
    scanf("%d", &dt->Spouse[1]);
}


void InputGrandchildrenFromSon(Family *dt) {
    printf("Is there a grandson from a son? Enter '0' for no, '1' for yes\n");
    scanf("%d", &dt->GrandchildrenFromSon[0]);

    printf("How many granddaughters from a son? Enter '0' if none, or the number if any\n");
    scanf("%d", &dt->GrandchildrenFromSon[1]);
}


void InputBrothers(Family *dt) {
    printf("Is there a full brother? Enter '0' for no, '1' for yes\n");
    scanf("%d", &dt->Brothers[0]);
    printf("Is there a paternal brother (same father)? Enter '0' for no, '1' for yes\n");
    scanf("%d", &dt->Brothers[1]);
    printf("How many maternal brothers (same mother)? Enter '0' if none, or the number if any\n");
    scanf("%d", &dt->Brothers[2]);
}


void InputSisters(Family *dt) {
    printf("How many full sisters? Enter '0' if none, or the number if any\n");
    scanf("%d", &dt->Sisters[0]);
    printf("How many paternal sisters (same father)? Enter '0' if none, or the number if any\n");
    scanf("%d", &dt->Sisters[1]);
    printf("How many maternal sisters (same mother)? Enter '0' if none, or the number if any\n");
    scanf("%d", &dt->Sisters[2]);
}


void InputGrandparents(Family *dt) {
    printf("Is the grandfather alive? Enter '0' for no, '1' for yes\n");
    scanf("%d", &dt->Grandparents[0]);
    printf("Is the grandmother alive? Enter '0' for no, '1' for yes\n");
    scanf("%d", &dt->Grandparents[1]);
}


void CalculateParentShares(Family dt, float *ShareHusband, float *ShareWife, float *ShareFather, float *ShareMother) {
    float remaining = 0.0f;

    *ShareHusband = 0.0f;
    *ShareWife = 0.0f;
    *ShareFather = 0.0f;
    *ShareMother = 0.0f;

    if ((dt.Spouse[0] == 1 && dt.Children[0] == 0 && dt.Children[1] == 0) || (dt.GrandchildrenFromSon[0] == 0 && dt.GrandchildrenFromSon[1] == 0)) {
        *ShareHusband = (1.0f / 2.0f) * dt.Inheritance;
    }
    else if ((dt.Spouse[0] == 1 && dt.Children[0] == 1 && dt.Children[1] == 1) || (dt.GrandchildrenFromSon[0] == 1 && dt.GrandchildrenFromSon[1] == 1)) {
        *ShareHusband = (1.0f / 4.0f) * dt.Inheritance;
    }

    if ((dt.Spouse[1] == 1 && dt.Children[0] == 0 && dt.Children[1] == 0) || (dt.GrandchildrenFromSon[0] == 0 && dt.GrandchildrenFromSon[1] == 0)) {
        *ShareWife = (1.0f / 4.0f) * dt.Inheritance;
    }
    else if ((dt.Spouse[1] == 1 && dt.Children[0] == 1 && dt.Children[1] == 1) || (dt.GrandchildrenFromSon[0] == 1 && dt.GrandchildrenFromSon[1] == 1)) {
        *ShareWife = (1.0f / 8.0f) * dt.Inheritance;
    }

    if ((dt.Parents2[0] == 1 && dt.Children[0] == 1 && dt.Children[1] == 1) || (dt.GrandchildrenFromSon[0] == 1 && dt.GrandchildrenFromSon[1] == 1)) {
        *ShareFather = (1.0f / 6.0f) * dt.Inheritance;
    }

    if ((dt.Parents2[1] == 1 && dt.Children[0] == 1 && dt.Children[1] == 1) || (dt.GrandchildrenFromSon[0] == 1 && dt.GrandchildrenFromSon[1] == 1) || dt.Brothers[0] >= 2 || dt.Brothers[1] >= 2 || dt.Brothers[2] >= 2 || dt.Sisters[0] >= 2 || dt.Sisters[1] >= 2 || dt.Sisters[2] >= 2) {
        *ShareMother = (1.0f / 6.0f) * dt.Inheritance;
    }
    else if ((dt.Parents2[1] == 1 && dt.Children[0] == 0 && dt.Children[1] == 0) || (dt.GrandchildrenFromSon[0] == 0 && dt.GrandchildrenFromSon[1] == 0) || dt.Brothers[0] == 0 || dt.Brothers[1] == 0 || dt.Brothers[2] == 0 || dt.Sisters[0] == 0 || dt.Sisters[1] == 0 || dt.Sisters[2] == 0) {
        *ShareMother = (1.0f / 3.0f) * dt.Inheritance;
    }

    if (dt.Spouse[1] == 0 && dt.Spouse[0] == 1 && dt.Parents2[1] == 1 && dt.Parents2[0] == 1 && dt.Children[0] == 1 && dt.Children[1] >= 1) {
        *ShareHusband = (1.0f / 2.0f) * dt.Inheritance;
        *ShareMother = (1.0f / 3.0f) * *ShareHusband;
        remaining = *ShareHusband - *ShareMother;
        *ShareFather = remaining;
    }
    else if (dt.Spouse[0] == 0 && dt.Spouse[1] == 1 && dt.Parents2[0] == 1 && dt.Parents2[1] == 1 && dt.Children[0] == 1 && dt.Children[1] >= 1) {
        *ShareWife = (1.0f / 4.0f) * dt.Inheritance;
        remaining = dt.Inheritance - *ShareWife;
        *ShareMother = (1.0f / 3.0f) * remaining;
        *ShareFather = remaining - *ShareMother;
    }
}


void CalculateGrandchildrenShares(Family dt, float *ShareGrandson, float *ShareGranddaughter) {
    *ShareGrandson = 0.0f;
    *ShareGranddaughter = 0.0f;

    if (dt.GrandchildrenFromSon[1] == 1 && dt.Children[0] == 0 && dt.Children[1] == 0) {
        *ShareGranddaughter = (1.0f / 2.0f) * dt.Inheritance;
    }
    else if (dt.GrandchildrenFromSon[1] >= 2 && dt.Children[0] == 0 && dt.Children[1] == 0) {
        *ShareGranddaughter = (2.0f / 3.0f) * dt.Inheritance;
    }
    else if (dt.GrandchildrenFromSon[1] >= 1 && dt.Children[1] == 1 && dt.Children[0] == 0) {
        *ShareGranddaughter = (1.0f / 6.0f) * dt.Inheritance;
    }
    else if ((dt.GrandchildrenFromSon[1] == 1 && dt.Children[0] == 1) || (dt.Children[1] >= 2)) {
        *ShareGranddaughter = 0.0f;
    }
}


void CalculateBrothers(Family dt, float *BrotherMaternal, float *BrotherFull, float *BrotherPaternal) {
    *BrotherMaternal = 0.0f;
    *BrotherFull = 0.0f;
    *BrotherPaternal = 0.0f;

    if (dt.Brothers[2] == 1 && dt.Children[0] == 0 && dt.Children[1] == 0 && dt.GrandchildrenFromSon[0] == 0 && dt.GrandchildrenFromSon[1] == 0 && dt.Parents2[0] == 0 && dt.Grandparents[0] == 0) {
        *BrotherMaternal = (1.0f / 6.0f) * dt.Inheritance;
    }
    else if (dt.Brothers[2] >= 2 && dt.Children[0] == 0 && dt.Children[1] == 0 && dt.GrandchildrenFromSon[0] == 0 && dt.GrandchildrenFromSon[1] == 0 && dt.Parents2[0] == 0 && dt.Grandparents[0] == 0) {
        *BrotherMaternal = (1.0f / 3.0f) * dt.Inheritance;
    }

    if ((dt.Brothers[2] >= 1 && dt.Children[0] == 1) || (dt.Children[1] >= 1 && dt.GrandchildrenFromSon[0] == 1) || (dt.GrandchildrenFromSon[1] >= 1 && dt.Parents2[0] == 1) || (dt.Grandparents[0] == 1)) {
        *BrotherMaternal = 0.0f;
    }
}


void CalculateSisters(Family dt, float *SisterMaternal, float *SisterPaternal, float *SisterFull) {
    *SisterMaternal = 0.0f;
    *SisterPaternal = 0.0f;
    *SisterFull = 0.0f;

    if (dt.Sisters[2] == 1 && dt.Children[0] == 0 && dt.Children[1] == 0 && dt.GrandchildrenFromSon[0] == 0 && dt.GrandchildrenFromSon[1] == 0 && dt.Parents2[0] == 0 && dt.Grandparents[0] == 0) {
        *SisterMaternal = (1.0f / 6.0f) * dt.Inheritance;
    }
    else if (dt.Sisters[2] >= 2 && dt.Children[0] == 0 && dt.Children[1] == 0 && dt.GrandchildrenFromSon[0] == 0 && dt.GrandchildrenFromSon[1] == 0 && dt.Parents2[0] == 0 && dt.Grandparents[0] == 0) {
        *SisterMaternal = (1.0f / 3.0f) * dt.Inheritance;
    }

    if ((dt.Sisters[2] >= 1 && dt.Children[0] == 1) || (dt.Children[1] >= 1 && dt.GrandchildrenFromSon[0] == 1) || (dt.GrandchildrenFromSon[1] >= 1 && dt.Parents2[0] == 1) || (dt.Grandparents[0] == 1)) {
        *SisterMaternal = 0.0f;
    }

    if (dt.Sisters[1] == 1 && dt.Children[1] == 0 && dt.GrandchildrenFromSon[1] == 0 && dt.Sisters[0] == 0) {
        *SisterPaternal = (1.0f / 2.0f) * dt.Inheritance;
    }
    else if (dt.Sisters[1] >= 2 && dt.Children[1] == 0 && dt.GrandchildrenFromSon[1] == 0 && dt.Sisters[0] == 0) {
        *SisterPaternal = (2.0f / 3.0f) * dt.Inheritance;
    }
    else if (dt.Sisters[1] == 1 && dt.Sisters[0] == 1 && dt.Children[1] == 0 && dt.GrandchildrenFromSon[1] == 0) {
        *SisterPaternal = (1.0f / 6.0f) * dt.Inheritance;
    }

    if (dt.Parents2[0] == 1 || dt.Children[0] >= 1 || dt.GrandchildrenFromSon[0] >= 1) {
        *SisterPaternal = 0.0f;
    }

    if (dt.Sisters[0] == 1 && dt.Brothers[0] == 0 && dt.Parents2[0] == 0 && dt.Children[0] == 0 && dt.GrandchildrenFromSon[0] == 0) {
        *SisterFull = (1.0f / 2.0f) * dt.Inheritance;
    }
    else if (dt.Sisters[0] >= 2 && dt.Brothers[0] == 0 && dt.Parents2[0] == 0 && dt.Children[0] == 0 && dt.GrandchildrenFromSon[0] == 0) {
        *SisterFull = (2.0f / 3.0f) * dt.Inheritance;
    }

    if (dt.Sisters[0] >= 1 || dt.Parents2[0] == 1 || dt.Children[0] >= 1 || dt.GrandchildrenFromSon[0] >= 1) {
        *SisterFull = 0.0f;
    }
}


void CalculateGrandmotherShare(Family dt, float *ShareGrandmother) {
    *ShareGrandmother = 0.0f;
    if (dt.Grandparents[1] >= 1) {
        *ShareGrandmother = (1.0f / 6.0f) * dt.Inheritance;
    }
}


void CalculateGrandfatherShare(Family dt, float *ShareGrandfather) {
    if (dt.Spouse[0] == 1) {
        *ShareGrandfather = 0.0f;
        return;
    }

    if (dt.Children[0] > 0 || dt.Children[1] > 0) {
        *ShareGrandfather = (1.0f / 6.0f) * dt.Inheritance;
        return;
    }

    *ShareGrandfather = 0.0f; // will be processed in ashabah if needed
}


void CalculateChildrenShares(Family dt, float *ShareDaughtersTotal) {
    *ShareDaughtersTotal = 0.0f;

    if (dt.Children[0] >= 1 && dt.Children[1] >= 1) {
        int totalParts = (dt.Children[0] * 2) + dt.Children[1];
        float onePart = dt.Inheritance / (float)totalParts;
        *ShareDaughtersTotal = onePart * dt.Children[1];
    }
    else if (dt.Children[1] == 1 && dt.Children[0] == 0) {
        *ShareDaughtersTotal = (1.0f / 2.0f) * dt.Inheritance;
    }
    else if (dt.Children[1] >= 2 && dt.Children[0] == 0) {
        *ShareDaughtersTotal = (2.0f / 3.0f) * dt.Inheritance;
    }
}


void DistributeAshabah(Family dt, float *ShareFather, float *ShareGrandfather, float *ShareHusband, float *ShareWife, float *ShareGrandson, float *ShareGranddaughter, float *ShareMother, float *BrotherMaternal, float *BrotherFull, float *BrotherPaternal, float *SisterMaternal, float *SisterFull, float *SisterPaternal, float *ShareGrandmother, float *ShareDaughtersTotal) {
    float remaining = (float)dt.Inheritance - (*ShareMother + *ShareGrandmother + *ShareHusband + *ShareWife + *ShareDaughtersTotal + *BrotherMaternal + *SisterMaternal + *ShareGranddaughter + *SisterFull + *SisterPaternal + *ShareFather);

    if (dt.Children[0] >= 1) {
        int totalParts = (dt.Children[0] * 2) + dt.Children[1];
        float onePart = remaining / (float)totalParts;

        *ShareGrandfather = 0.0f;
        *BrotherMaternal = 0.0f;
        *BrotherFull = 0.0f;
        *BrotherPaternal = 0.0f;

        printf("=== ASHABAH (SONS PRESENT) ===\n");
        printf("Each son receives: %.2f\n", onePart * 2.0f);
        printf("Total for daughters was calculated previously.\n");
        return;
    }

    if (dt.Grandparents[0] == 1) {
        *ShareGrandfather += remaining; // Grandfather takes all remaining

        printf("=== ASHABAH (GRANDFATHER) ===\n");
        printf("Grandfather takes all remaining: %.2f\n", remaining);
        return;
    }

    if (dt.Brothers[0] >= 1 || dt.Brothers[1] >= 1 || dt.Brothers[2] >= 1) {
        int numBrothers = dt.Brothers[0] + dt.Brothers[1] + dt.Brothers[2];
        if (numBrothers > 0) {
            float onePart = remaining / (float)numBrothers;
            *BrotherMaternal += onePart * dt.Brothers[2];
            *BrotherFull += onePart * dt.Brothers[0];
            *BrotherPaternal += onePart * dt.Brothers[1];

            printf("=== ASHABAH (BROTHERS) ===\n");
            printf("Each brother receives according to his group\n");
            return;
        }
    }

    printf("No ashabah heirs are entitled to the remainder.\n");
}


int main() {
    Family dt = {0};

    printf("                -----ISLAMIC INHERITANCE CALCULATION PROGRAM-----             \n");

    InputInheritance(&dt);
    InputChildren(&dt);
    InputGrandchildrenFromSon(&dt);
    InputSpouse(&dt);
    InputParents2(&dt);
    InputBrothers(&dt);
    InputSisters(&dt);
    InputGrandparents(&dt);

    float ShareHusband = 0.0f, ShareWife = 0.0f, ShareFather = 0.0f, ShareMother = 0.0f;
    float ShareGrandson = 0.0f, ShareGranddaughter = 0.0f;
    float BrotherMaternal = 0.0f, BrotherFull = 0.0f, BrotherPaternal = 0.0f;
    float SisterMaternal = 0.0f, SisterFull = 0.0f, SisterPaternal = 0.0f;
    float ShareGrandmother = 0.0f, ShareGrandfather = 0.0f, ShareDaughtersTotal = 0.0f;

    CalculateParentShares(dt, &ShareHusband, &ShareWife, &ShareFather, &ShareMother);
    CalculateGrandchildrenShares(dt, &ShareGrandson, &ShareGranddaughter);
    CalculateBrothers(dt, &BrotherMaternal, &BrotherFull, &BrotherPaternal);
    CalculateSisters(dt, &SisterMaternal, &SisterPaternal, &SisterFull);
    CalculateGrandmotherShare(dt, &ShareGrandmother);
    CalculateGrandfatherShare(dt, &ShareGrandfather);
    CalculateChildrenShares(dt, &ShareDaughtersTotal);

    DistributeAshabah(dt, &ShareFather, &ShareGrandfather, &ShareHusband, &ShareWife, &ShareGrandson, &ShareGranddaughter, &ShareMother, &BrotherMaternal, &BrotherFull, &BrotherPaternal, &SisterMaternal, &SisterFull, &SisterPaternal, &ShareGrandmother, &ShareDaughtersTotal);

    printf("\n--- INHERITANCE DISTRIBUTION RESULTS ---\n");
    printf("Total inheritance: %.2f\n", dt.Inheritance);
    printf("Husband's share: %.2f\n", ShareHusband);
    printf("Wife's share: %.2f\n", ShareWife);
    printf("Father's share: %.2f\n", ShareFather);
    printf("Mother's share: %.2f\n", ShareMother);
    printf("Grandfather's share: %.2f\n", ShareGrandfather);
    printf("Grandmother's share: %.2f\n", ShareGrandmother);
    printf("Grandson's share: %.2f\n", ShareGrandson);
    printf("Granddaughter's share: %.2f\n", ShareGranddaughter);
    printf("Daughters (total): %.2f\n", ShareDaughtersTotal);
    printf("Brothers - Maternal: %.2f, Full: %.2f, Paternal: %.2f\n", BrotherMaternal, BrotherFull, BrotherPaternal);
    printf("Sisters - Maternal: %.2f, Full: %.2f, Paternal: %.2f\n", SisterMaternal, SisterFull, SisterPaternal);

    return 0;
}

