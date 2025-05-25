#include <gtk/gtk.h>
#include <string.h>
#include "diagnosis1.h"
#include "advice1.h"

#define MAX_SYMPTOMS 10

// Global variables for UI widgets and data
GtkWidget *window;
GtkWidget *symptom_box;
GtkWidget *diagnosis_label;
GtkWidget *name_entry;
GtkWidget *spin_symptom_count;

struct symptom symptoms_selected[MAX_SYMPTOMS];
int symptom_count = 1;

// Sample symptom list for dropdown
const char *symptoms[] = {
    "Fever", "Cough", "Headache", "Fatigue", "Cold", "Sore Throat", NULL
};

// Helper function: show input dialog to get int input for severity grading
int show_int_input_dialog(const char *message) {
    GtkWidget *dialog, *content_area, *entry;
    gint result;
    int value = -1;

    dialog = gtk_dialog_new_with_buttons("Input Required",
                                         GTK_WINDOW(window),
                                         GTK_DIALOG_MODAL,
                                         "_OK",
                                         GTK_RESPONSE_OK,
                                         "_Cancel",
                                         GTK_RESPONSE_CANCEL,
                                         NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *label = gtk_label_new(message);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    entry = gtk_entry_new();
    gtk_entry_set_input_purpose(GTK_ENTRY(entry), GTK_INPUT_PURPOSE_NUMBER);
    gtk_container_add(GTK_CONTAINER(content_area), entry);

    gtk_widget_show_all(dialog);

    result = gtk_dialog_run(GTK_DIALOG(dialog));
    if (result == GTK_RESPONSE_OK) {
        const char *text = gtk_entry_get_text(GTK_ENTRY(entry));
        if (text != NULL && strlen(text) > 0) {
            value = atoi(text);
        }
    }

    gtk_widget_destroy(dialog);
    return value;
}

// Create symptom dropdown combo box
GtkWidget* create_symptom_dropdown(int index) {
    GtkWidget *combo = gtk_combo_box_text_new();
    for (int i = 0; symptoms[i] != NULL; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), symptoms[i]);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0);

    if (strlen(symptoms_selected[index].name) > 0) {
        // Optionally preselect saved symptom
        for (int i = 0; symptoms[i] != NULL; i++) {
            if (strcmp(symptoms_selected[index].name, symptoms[i]) == 0) {
                gtk_combo_box_set_active(GTK_COMBO_BOX(combo), i);
                break;
            }
        }
    }
    return combo;
}

// Update dropdowns when symptom count changes
void on_symptom_count_changed(GtkSpinButton *spin, gpointer user_data) {
    symptom_count = gtk_spin_button_get_value_as_int(spin);

    // Clear old widgets
    GList *children = gtk_container_get_children(GTK_CONTAINER(symptom_box));
    for (GList *iter = children; iter != NULL; iter = g_list_next(iter)) {
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    }
    g_list_free(children);

    // Add new dropdowns
    for (int i = 0; i < symptom_count; i++) {
        GtkWidget *combo = create_symptom_dropdown(i);
        gtk_box_pack_start(GTK_BOX(symptom_box), combo, FALSE, FALSE, 5);
    }
    gtk_widget_show_all(symptom_box);
}

void intro_gui(struct symptom s0[]) {
    for (int i = 0; i < symptom_count; i++) {
        if (strcmp(s0[i].name, "Fever") == 0) {
            int temp = show_int_input_dialog("Enter body temperature in Celsius (e.g. 37, 38):");
            if (temp > 37 && temp < 38)
                s0[i].severity = 1;
            else if (temp >= 38 && temp < 39)
                s0[i].severity = 2;
            else if (temp >= 39)
                s0[i].severity = 3;
            else
                s0[i].severity = 1;
        }
        else if (strcmp(s0[i].name, "Cough") == 0) {
            int freq = show_int_input_dialog("Enter cough frequency in the last hour:");
            if (freq < 5)
                s0[i].severity = 1;
            else if (freq >= 5 && freq < 15)
                s0[i].severity = 2;
            else
                s0[i].severity = 3;
        }
        else if (strcmp(s0[i].name, "Headache") == 0) {
            int pupil = show_int_input_dialog("Enter:\n4 for discomfort under normal light\n5 for discomfort under bright light\n6 for staying in dark room");
            if (pupil == 4)
                s0[i].severity = 1;
            else if (pupil == 5)
                s0[i].severity = 2;
            else if (pupil == 6)
                s0[i].severity = 3;
            else
                s0[i].severity = 1;
        }
        else if (strcmp(s0[i].name, "Fatigue") == 0) {
            int hours = show_int_input_dialog("Enter number of hours you felt tired:");
            if (hours < 2)
                s0[i].severity = 1;
            else if (hours >= 2 && hours <= 5)
                s0[i].severity = 2;
            else
                s0[i].severity = 3;
        }
        else if (strcmp(s0[i].name, "Cold") == 0) {
            int sneezes = show_int_input_dialog("Enter number of sneezes in the past hour:");
            if (sneezes < 3)
                s0[i].severity = 1;
            else if (sneezes >= 3 && sneezes <= 8)
                s0[i].severity = 2;
            else
                s0[i].severity = 3;
        }
        else if (strcmp(s0[i].name, "Sore Throat") == 0) {
            int throat = show_int_input_dialog("Enter:\n4 for slight redness no swelling\n5 for red throat mild swelling\n6 for bright red throat swollen tonsils or white patches");
            if (throat == 4)
                s0[i].severity = 1;
            else if (throat == 5)
                s0[i].severity = 2;
            else if (throat == 6)
                s0[i].severity = 3;
            else
                s0[i].severity = 1;
        }
        else {
            // Default severity for unknown symptom
            s0[i].severity = 1;
        }
    }
}

void on_diagnose_button_clicked(GtkButton *button, gpointer user_data) {
    // Get user name
    const char *username = gtk_entry_get_text(GTK_ENTRY(name_entry));
    if (strlen(username) == 0) {
        gtk_label_set_text(GTK_LABEL(diagnosis_label), "Please enter your name.");
        return;
    }

    // Get symptom count and selected symptoms from dropdowns
    GList *children = gtk_container_get_children(GTK_CONTAINER(symptom_box));
    if (g_list_length(children) != symptom_count) {
        gtk_label_set_text(GTK_LABEL(diagnosis_label), "Symptom dropdown mismatch.");
        g_list_free(children);
        return;
    }

    int i = 0;
    for (GList *iter = children; iter != NULL && i < symptom_count; iter = g_list_next(iter), i++) {
        GtkComboBoxText *combo = GTK_COMBO_BOX_TEXT(iter->data);
        const char *selected_symptom = gtk_combo_box_text_get_active_text(combo);
        if (selected_symptom == NULL || strlen(selected_symptom) == 0) {
            gtk_label_set_text(GTK_LABEL(diagnosis_label), "Please select all symptoms.");
            g_list_free(children);
            return;
        }
        strncpy(symptoms_selected[i].name, selected_symptom, sizeof(symptoms_selected[i].name));
        symptoms_selected[i].severity = 0; // Reset severity
        g_free((gpointer)selected_symptom);
    }
    g_list_free(children);

    // Run your GUI intro (severity input dialogs)
    intro_gui(symptoms_selected);

    // Grade severity (your original function - keep it or remove if intro_gui covers)
    severity_grader(symptoms_selected);

    // Get diagnosis severity code
    int final_severity = diagnose(symptoms_selected);

    // Prepare advice message string (instead of printing on terminal)
    char advice_text[1024];
    if (final_severity == 1) {
        snprintf(advice_text, sizeof(advice_text),
            "🟢 Mild Severity\nAdvice:\n- Get adequate rest and stay hydrated.\n- Monitor symptoms.\n- Light diet and avoid stress.\n- OTC meds if needed.\n- No immediate doctor visit needed.");
    }
    else if (final_severity == 2) {
        snprintf(advice_text, sizeof(advice_text),
            "🟠 Moderate Severity\nAdvice:\n- Monitor symptoms closely.\n- Use appropriate medication.\n- Limit physical activity.\n- Seek medical attention if worsens.");
    }
    else if (final_severity == 3) {
        snprintf(advice_text, sizeof(advice_text),
            "🔴 Severe Severity\nAdvice:\n- Seek immediate medical attention.\n- Do not rely on home remedies or OTC medication.\n- Avoid travel or exertion until cleared by a doctor.\n- Inform family or caretaker.\n- Be prepared for tests or hospitalization.");
    }
    else {
        snprintf(advice_text, sizeof(advice_text), "No sufficient data to provide advice.");
    }

    char output[2048];
    snprintf(output, sizeof(output), "Hello %s,\n%s", username, advice_text);

    gtk_label_set_text(GTK_LABEL(diagnosis_label), output);
}

// Main UI setup
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Symptom Diagnosis");
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Vertical box layout
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Name entry
    GtkWidget *name_label = gtk_label_new("Enter your name:");
    gtk_box_pack_start(GTK_BOX(vbox), name_label, FALSE, FALSE, 5);
    name_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), name_entry, FALSE, FALSE, 5);

    // Symptom count spin button
    GtkWidget *count_label = gtk_label_new("Select number of symptoms:");
    gtk_box_pack_start(GTK_BOX(vbox), count_label, FALSE, FALSE, 5);
    spin_symptom_count = gtk_spin_button_new_with_range(1, MAX_SYMPTOMS, 1);
    gtk_box_pack_start(GTK_BOX(vbox), spin_symptom_count, FALSE, FALSE, 5);
    g_signal_connect(spin_symptom_count, "value-changed", G_CALLBACK(on_symptom_count_changed), NULL);

    // Symptom dropdown container
    symptom_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(vbox), symptom_box, FALSE, FALSE, 5);

    // Initially create one symptom dropdown
    on_symptom_count_changed(GTK_SPIN_BUTTON(spin_symptom_count), NULL);

    // Diagnose button
    GtkWidget *diagnose_button = gtk_button_new_with_label("Get Diagnosis and Advice");
    gtk_box_pack_start(GTK_BOX(vbox), diagnose_button, FALSE, FALSE, 10);
    g_signal_connect(diagnose_button, "clicked", G_CALLBACK(on_diagnose_button_clicked), NULL);

    // Label for output
    diagnosis_label = gtk_label_new("");
    gtk_label_set_line_wrap(GTK_LABEL(diagnosis_label), TRUE);
    gtk_box_pack_start(GTK_BOX(vbox), diagnosis_label, FALSE, FALSE, 5);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}
