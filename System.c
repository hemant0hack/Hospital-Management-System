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
    char address[100];
    char disease[100];
    char REFERRED_BY[100];
    char admissionDateTime[40];
} Patient;

typedef struct {
    char id[20];
    char name[100];
    char specialization[100];
    int experience;
} Doctor;

typedef struct {
    char id[20];
    char patientName[100];
    char doctorName[100];
    char appointmentDateTime[40];
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
    sprintf(buffer, "%02d-%02d-%04d %02d:%02d:%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
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
    printf("Enter Patient Address: ");
    scanf("%s", patients[patientCount].address);
    printf("Enter Patient Disease: ");
    scanf("%s", patients[patientCount].disease);
    printf("Enter Referred By: ");
    scanf("%s", patients[patientCount].REFERRED_BY);
    getCurrentDateTime(patients[patientCount].admissionDateTime);
    patientCount++;
    printf("Patient added successfully!\n");
}

// Function to view all patients
void viewPatients() {
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %s | Name: %s | Age: %d | Gender: %s | Address: %s | Disease: %s | REFERRED_BY: %s | Admission DateTime: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].address, patients[i].disease, patients[i].REFERRED_BY, patients[i].admissionDateTime);
    }
}

// Function to edit a patient by ID
void editPatient() {
    char id[20];
    printf("Enter Patient ID to edit: ");
    scanf("%s", id);
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].id, id) == 0) {
            int choice;
            printf("What do you want to edit?\n");
            printf("1. Name\n");
            printf("2. Age\n");
            printf("3. Gender\n");
            printf("4. Address\n");
            printf("5. Disease\n");
            printf("6. Referred By\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter new Patient Name: ");
                    scanf("%s", patients[i].name);
                    break;
                case 2:
                    printf("Enter new Patient Age: ");
                    scanf("%d", &patients[i].age);
                    break;
                case 3:
                    printf("Enter new Patient Gender: ");
                    scanf("%s", patients[i].gender);
                    break;
                case 4:
                    printf("Enter new Patient Address: ");
                    scanf("%s", patients[i].address);
                    break;
                case 5:
                    printf("Enter new Patient Disease: ");
                    scanf("%s", patients[i].disease);
                    break;
                case 6:
                    printf("Enter new Referred By: ");
                    scanf("%s", patients[i].REFERRED_BY);
                    break;
                default:
                    printf("Invalid choice!\n");
                    return;
            }
            getCurrentDateTime(patients[i].admissionDateTime);
            printf("Patient record updated successfully!\n");
            return;
        }
    }
    printf("Patient not found!\n");
}

// Function to view a patient by ID
void viewPatientById() {
    char id[20];
    printf("Enter Patient ID to view: ");
    scanf("%s", id);
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].id, id) == 0) {
            printf("ID: %s | Name: %s | Age: %d | Gender: %s | Address: %s | Disease: %s | REFERRED_BY: %s | Admission DateTime: %s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].address, patients[i].disease, patients[i].REFERRED_BY, patients[i].admissionDateTime);
            return;
        }
    }
    printf("Patient not found!\n");
}

// Function to delete a patient by ID
void deletePatientById() {
    char id[20];
    printf("Enter Patient ID to delete: ");
    scanf("%s", id);
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].id, id) == 0) {
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient record deleted successfully!\n");
            return;
        }
    }
    printf("Patient not found!\n");
}

// Function to add a new doctor
void addDoctor() {
    printf("Enter Doctor ID: ");
    scanf("%s", doctors[doctorCount].id);
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
        printf("ID: %s | Name: %s | Specialization: %s | Experience: %d years\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].experience);
    }
}

// Function to edit a doctor by ID
void editDoctor() {
    char id[20];
    printf("Enter Doctor ID to edit: ");
    scanf("%s", id);
    for (int i = 0; i < doctorCount; i++) {
        if (strcmp(doctors[i].id, id) == 0) {
            int choice;
            printf("What do you want to edit?\n");
            printf("1. Name\n");
            printf("2. Specialization\n");
            printf("3. Experience\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter new Doctor Name: ");
                    scanf("%s", doctors[i].name);
                    break;
                case 2:
                    printf("Enter new Doctor Specialization: ");
                    scanf("%s", doctors[i].specialization);
                    break;
                case 3:
                    printf("Enter new Doctor Experience (years): ");
                    scanf("%d", &doctors[i].experience);
                    break;
                default:
                    printf("Invalid choice!\n");
                    return;
            }
            printf("Doctor record updated successfully!\n");
            return;
        }
    }
    printf("Doctor not found!\n");
}

// Function to view a doctor by ID
void viewDoctorById() {
    char id[20];
    printf("Enter Doctor ID to view: ");
    scanf("%s", id);
    for (int i = 0; i < doctorCount; i++) {
        if (strcmp(doctors[i].id, id) == 0) {
            printf("ID: %s | Name: %s | Specialization: %s | Experience: %d years\n", doctors[i].id, doctors[i].name, doctors[i].specialization, doctors[i].experience);
            return;
        }
    }
    printf("Doctor not found!\n");
}

// Function to delete a doctor by ID
void deleteDoctorById() {
    char id[20];
    printf("Enter Doctor ID to delete: ");
    scanf("%s", id);
    for (int i = 0; i < doctorCount; i++) {
        if (strcmp(doctors[i].id, id) == 0) {
            for (int j = i; j < doctorCount - 1; j++) {
                doctors[j] = doctors[j + 1];
            }
            doctorCount--;
            printf("Doctor record deleted successfully!\n");
            return;
        }
    }
    printf("Doctor not found!\n");
}

// Function to add a new appointment
void addAppointment() {
    printf("Enter Appointment ID: ");
    scanf("%s", appointments[appointmentCount].id);
    printf("Enter Patient Name: ");
    scanf("%s", appointments[appointmentCount].patientName);
    printf("Enter Doctor Name: ");
    scanf("%s", appointments[appointmentCount].doctorName);
    getCurrentDateTime(appointments[appointmentCount].appointmentDateTime);
    appointmentCount++;
    printf("Appointment added successfully!\n");
}

// Function to view all appointments
void viewAppointments() {
    for (int i = 0; i < appointmentCount; i++) {
        printf("ID: %s | Patient Name: %s | Doctor Name: %s | Appointment DateTime: %s\n", appointments[i].id, appointments[i].patientName, appointments[i].doctorName, appointments[i].appointmentDateTime);
    }
}

// Function to edit an appointment by ID
void editAppointment() {
    char id[20];
    printf("Enter Appointment ID to edit: ");
    scanf("%s", id);
    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].id, id) == 0) {
            int choice;
            printf("What do you want to edit?\n");
            printf("1. Patient Name\n");
            printf("2. Doctor Name\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter new Patient Name: ");
                    scanf("%s", appointments[i].patientName);
                    break;
                case 2:
                    printf("Enter new Doctor Name: ");
                    scanf("%s", appointments[i].doctorName);
                    break;
                default:
                    printf("Invalid choice!\n");
                    return;
            }
            getCurrentDateTime(appointments[i].appointmentDateTime);
            printf("Appointment record updated successfully!\n");
            return;
        }
    }
    printf("Appointment not found!\n");
}

// Function to view an appointment by ID
void viewAppointmentById() {
    char id[20];
    printf("Enter Appointment ID to view: ");
    scanf("%s", id);
    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].id, id) == 0) {
            printf("ID: %s | Patient Name: %s | Doctor Name: %s | Appointment DateTime: %s\n", appointments[i].id, appointments[i].patientName, appointments[i].doctorName, appointments[i].appointmentDateTime);
            return;
        }
    }
    printf("Appointment not found!\n");
}

// Function to delete an appointment by ID
void deleteAppointmentById() {
    char id[20];
    printf("Enter Appointment ID to delete: ");
    scanf("%s", id);
    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointments[i].id, id) == 0) {
            for (int j = i; j < appointmentCount - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            appointmentCount--;
            printf("Appointment record deleted successfully!\n");
            return;
        }
    }
    printf("Appointment not found!\n");
}

// Function to reset all data
void resetAllData() {
    patientCount = 0;
    doctorCount = 0;
    appointmentCount = 0;
    printf("All data reset successfully!\n");
}

// Main function to display the menu and handle user choices
int main() {
    int choice;
    while (1) {
        printf("\n1. Patients\n");
        printf("2. Doctors\n");
        printf("3. Appointments\n");
        printf("4. Reset All Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n1. Add Patient\n");
                printf("2. View Patients\n");
                printf("3. Edit Patient\n");
                printf("4. View Patient by ID\n");
                printf("5. Delete Patient by ID\n");
                printf("Enter your choice: ");
                int patientChoice;
                scanf("%d", &patientChoice);
                switch (patientChoice) {
                    case 1:
                        addPatient();
                        break;
                    case 2:
                        viewPatients();
                        break;
                    case 3:
                        editPatient();
                        break;
                    case 4:
                        viewPatientById();
                        break;
                    case 5:
                        deletePatientById();
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 2:
                printf("\n1. Add Doctor\n");
                printf("2. View Doctors\n");
                printf("3. Edit Doctor\n");
                printf("4. View Doctor by ID\n");
                printf("5. Delete Doctor by ID\n");
                printf("Enter your choice: ");
                int doctorChoice;
                scanf("%d", &doctorChoice);
                switch (doctorChoice) {
                    case 1:
                        addDoctor();
                        break;
                    case 2:
                        viewDoctors();
                        break;
                    case 3:
                        editDoctor();
                        break;
                    case 4:
                        viewDoctorById();
                        break;
                    case 5:
                        deleteDoctorById();
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 3:
                printf("\n1. Add Appointment\n");
                printf("2. View Appointments\n");
                printf("3. Edit Appointment\n");
                printf("4. View Appointment by ID\n");
                printf("5. Delete Appointment by ID\n");
                printf("Enter your choice: ");
                int appointmentChoice;
                scanf("%d", &appointmentChoice);
                switch (appointmentChoice) {
                    case 1:
                        addAppointment();
                        break;
                    case 2:
                        viewAppointments();
                        break;
                    case 3:
                        editAppointment();
                        break;
                    case 4:
                        viewAppointmentById();
                        break;
                    case 5:
                        deleteAppointmentById();
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            case 4:
                resetAllData();
                break;
            case 5:
                printf("----------------Thank You----------------");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}