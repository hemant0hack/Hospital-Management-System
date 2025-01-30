#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures
typedef struct {
    int id;
    char name[50];
    int age;
    char disease[100];
} Patient;

typedef struct {
    int id;
    char name[50];
    char specialty[50];
} Doctor;

typedef struct {
    int patientId;
    int doctorId;
    char date[20];
} Appointment;

// Function to add a patient
void addPatient() {
    FILE *file = fopen("patients.dat", "ab");
    Patient p;
    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Patient Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);
    fwrite(&p, sizeof(Patient), 1, file);
    fclose(file);
    printf("Patient added successfully!\n");
}

// Function to display all patients
void displayPatients() {
    FILE *file = fopen("patients.dat", "rb");
    Patient p;
    printf("\nPatient List:\n");
    while (fread(&p, sizeof(Patient), 1, file)) {
        printf("ID: %d, Name: %s, Age: %d, Disease: %s\n", p.id, p.name, p.age, p.disease);
    }
    fclose(file);
}

// Function to add a doctor
void addDoctor() {
    FILE *file = fopen("doctors.dat", "ab");
    Doctor d;
    printf("Enter Doctor ID: ");
    scanf("%d", &d.id);
    printf("Enter Doctor Name: ");
    scanf(" %[^\n]", d.name);
    printf("Enter Specialty: ");
    scanf(" %[^\n]", d.specialty);
    fwrite(&d, sizeof(Doctor), 1, file);
    fclose(file);
    printf("Doctor added successfully!\n");
}

// Function to display all doctors
void displayDoctors() {
    FILE *file = fopen("doctors.dat", "rb");
    Doctor d;
    printf("\nDoctor List:\n");
    while (fread(&d, sizeof(Doctor), 1, file)) {
        printf("ID: %d, Name: %s, Specialty: %s\n", d.id, d.name, d.specialty);
    }
    fclose(file);
}

// Function to schedule an appointment
void scheduleAppointment() {
    FILE *file = fopen("appointments.dat", "ab");
    Appointment a;
    printf("Enter Patient ID: ");
    scanf("%d", &a.patientId);
    printf("Enter Doctor ID: ");
    scanf("%d", &a.doctorId);
    printf("Enter Appointment Date (DD/MM/YYYY): ");
    scanf(" %[^\n]", a.date);
    fwrite(&a, sizeof(Appointment), 1, file);
    fclose(file);
    printf("Appointment scheduled successfully!\n");
}

// Function to display all appointments
void displayAppointments() {
    FILE *file = fopen("appointments.dat", "rb");
    Appointment a;
    printf("\nAppointment List:\n");
    while (fread(&a, sizeof(Appointment), 1, file)) {
        printf("Patient ID: %d, Doctor ID: %d, Date: %s\n", a.patientId, a.doctorId, a.date);
    }
    fclose(file);
}

// Function to generate a bill for a patient
void generateBill() {
    int patientId;
    float consultationFee = 500, medicineCost, total;
    printf("Enter Patient ID: ");
    scanf("%d", &patientId);
    printf("Enter Medicine Cost: ");
    scanf("%f", &medicineCost);
    total = consultationFee + medicineCost;
    printf("\nBill for Patient ID %d\n", patientId);
    printf("Consultation Fee: $%.2f\n", consultationFee);
    printf("Medicine Cost: $%.2f\n", medicineCost);
    printf("Total Amount: $%.2f\n", total);
}

// Function to reset hospital data
void resetHospitalData() {
    FILE *file;
    file = fopen("patients.dat", "wb");
    fclose(file);
    file = fopen("doctors.dat", "wb");
    fclose(file);
    file = fopen("appointments.dat", "wb");
    fclose(file);
    printf("Hospital data reset successfully!\n");
}

// Main menu function
int main() {
    int choice;
    while (1) {
        printf("\nHospital Management System:\n");
        printf("1. Add Patient\n2. View Patients\n3. Add Doctor\n4. View Doctors\n5. Schedule Appointment\n6. View Appointments\n7. Generate Bill\n8. Reset Data\n9. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: addDoctor(); break;
            case 4: displayDoctors(); break;
            case 5: scheduleAppointment(); break;
            case 6: displayAppointments(); break;
            case 7: generateBill(); break;
            case 8: resetHospitalData(); break;
            case 9: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
