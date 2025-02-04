#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define structures for Patient, Doctor, and Appointment
typedef struct {
    char id[20];
    char name[100];
    int age;
    char gender[10];
    char disease[100];
    char admissionDateTime[30];
} Patient;

typedef struct {
    char id[20];
    char name[100];
    char specialization[100];
    int experience;
} Doctor;

typedef struct {
    char id[20];
    char patientId[20];
    char doctorId[20];
    char appointmentDateTime[30];
} Appointment;

// Declare arrays and counters for storing records
Patient patients[100];
Doctor doctors[100];
Appointment appointments[100];
int patientCount = 0;
int doctorCount = 0;
int appointmentCount = 0;

// Function to get the current date and time
void getCurrentDateTime(char* buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%02d-%02d-%d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// Function to add a new patient
void addPatient() {
    printf("Enter Patient ID: ");
    scanf("%s", patients[patientCount].id);
    printf("Enter Patient Name: ");
    scanf("%s", patients[patientCount].name);
    printf("Enter Patient Age: ");
    scanf("%d", &patients[patientCount].age);
    printf("Enter Patient Gender: ");
    scanf("%s", patients[patientCount].gender);
    printf("Enter Patient Disease: ");
    scanf("%s", patients[patientCount].disease);
    getCurrentDateTime(patients[patientCount].admissionDateTime);
    patientCount++;
    printf("Patient added successfully!\n");
}

// Function to view all patients
void viewPatients() {
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %s, Name: %s, Age: %d, Gender: %s, Disease: %s, Admission DateTime: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].disease, patients[i].admissionDateTime);
    }
}
// Function to add a new doctor
void addDoctor() {
    printf("Enter Doctor ID: ");
    scanf("%s", &doctors[doctorCount].id);
    printf("Enter Doctor Name: ");
    scanf("%s", doctors[doctorCount].name);
    printf("Enter Doctor Specialization: ");
    scanf("%s", doctors[doctorCount].specialization);
    printf("Enter Doctor Experience (years): ");
    scanf("%d", &doctors[doctorCount].experience);
    doctorCount++;
    printf("Doctor added successfully!\n");
}

// Function to view all doctors
void viewDoctors() {
    for (int i = 0; i < doctorCount; i++) {
        printf("ID: %s, Name: %s, Specialization: %s, Experience: %d years\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].experience);
    }
}


// Function to add a new appointment
void addAppointment() {
    printf("Enter Appointment ID: ");
    scanf("%s", &appointments[appointmentCount].id);
    printf("Enter Patient ID: ");
    scanf("%s", &appointments[appointmentCount].patientId);
    printf("Enter Doctor ID: ");
    scanf("%s", &appointments[appointmentCount].doctorId);
    printf("Enter Appointments Date :");
    scanf("%s", &appointments[appointmentCount].appointmentDateTime);
    appointmentCount++;
    printf("Appointment added successfully!\n");
}

// Function to view all appointments
void viewAppointments() {
    for (int i = 0; i < appointmentCount; i++) {
        printf("ID: %s, Patient ID: %s, Doctor ID: %s, Appointment DateTime: %s\n", appointments[i].id, appointments[i].patientId, appointments[i].doctorId, appointments[i].appointmentDateTime);
    }
}

// Main function to display the menu and handle user choices
int main() {
    int choice;
    while (1) {
        printf("\n1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Add Doctor\n");
        printf("4. View Doctors\n");
        printf("5. Add Appointment\n");
        printf("6. View Appointments\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                addDoctor();
                break;
            case 4:
                viewDoctors();
                break;
            case 5:
                addAppointment();
                break;
            case 6:
                viewAppointments();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}