#include "database.h"
#include "diagnosis.c"

Disease database[] = {
{"Dengue", {"fever", "rash", "joint pain", "bleeding", "eye pain"}, {9, 5, 7, 10, 6}},
{"Typhoid", {"high fever", "constipation", "abdominal pain", "slow pulse", "dry cough"}, {9, 4, 7, 5, 6}},
{"Malaria", {"chills", "sweating", "vomiting", "headache", "muscle pain"}, {8, 5, 7, 6, 6}},
{"COVID-19", {"dry cough", "loss of smell", "breathing difficulty", "sore throat", "fatigue"}, {6, 9, 10, 5, 5}},
{"Tuberculosis", {"weight loss", "night sweats", "blood in cough", "chest pain", "persistent cough"}, {7, 6, 10, 8, 9}},
{"Asthma", {"wheezing", "shortness of breath", "chest tightness", "coughing at night", "fatigue after exertion"}, {7, 10, 9, 6, 5}},
{"Migraine", {"throbbing headache", "nausea", "light sensitivity", "sound sensitivity", "blurred vision"}, {8, 6, 7, 6, 7}},
{"Pneumonia", {"chest pain when breathing", "cough with phlegm", "low oxygen", "chills", "short breath"}, {8, 7, 10, 6, 9}},
{"Jaundice", {"yellow skin", "yellow eyes", "dark urine", "light stools", "itchy skin"}, {8, 8, 7, 5, 4}},
{"UTI", {"burning urination", "frequent urination", "pelvic pain", "cloudy urine", "strong-smelling urine"}, {9, 8, 7, 6, 6}},
{"Common Cold", {"runny nose", "sneezing", "sore throat", "mild cough", "nasal congestion"}, {4, 3, 5, 4, 5}},
{"Mild Flu", {"low fever", "fatigue", "body ache", "mild chills", "dry throat"}, {5, 5, 6, 4, 4}},
{"Food Poisoning", {"nausea", "vomiting", "stomach cramps", "diarrhea", "mild fever"}, {5, 7, 6, 7, 5}},
{"Acid Reflux", {"heartburn", "chest discomfort", "sour taste", "burping", "nausea after meals"}, {7, 6, 5, 4, 5}},
{"Constipation", {"infrequent stools", "hard stool", "bloating", "stomach discomfort", "straining"}, {5, 6, 5, 5, 5}},
{"Dehydration", {"dry mouth", "dizziness", "less urination", "fatigue", "light-headedness"}, {5, 6, 7, 5, 6}},
{"Headache (non-migraine)", {"dull head pain", "pressure in forehead", "neck tightness", "irritability", "trouble focusing"}, {5, 4, 5, 4, 5}},
{"Seasonal Allergy", {"itchy eyes", "sneezing", "runny nose", "nasal congestion", "watery eyes"}, {6, 5, 4, 4, 5}},
{"Mild Skin Rash", {"red patches", "itching", "dryness", "slight swelling", "flaky skin"}, {6, 7, 5, 4, 4}},
{"Indigestion", {"bloating", "gas", "discomfort after eating", "burping", "heaviness"}, {6, 5, 6, 4, 5}},
{"Sinusitis", {"facial pain", "nasal congestion", "headache", "postnasal drip", "reduced smell"}, {6, 6, 5, 5, 5}},
{"Bronchitis", {"persistent cough", "chest discomfort", "mucus", "fatigue", "mild fever"}, {7, 6, 6, 5, 5}},
{"Ear Infection", {"ear pain", "hearing difficulty", "drainage", "fever", "irritability"}, {7, 6, 5, 5, 5}},
{"Gastritis", {"upper stomach pain", "nausea", "bloating", "vomiting", "loss of appetite"}, {6, 6, 5, 6, 5}},
{"Tonsillitis", {"sore throat", "swollen tonsils", "difficulty swallowing", "fever", "bad breath"}, {7, 8, 7, 6, 5}},
{"Chickenpox", {"itchy rash", "fever", "fatigue", "blisters", "headache"}, {8, 7, 6, 9, 5}},
{"Scabies", {"intense itching", "burrows on skin", "rash", "redness", "worse at night"}, {9, 7, 6, 6, 7}},
{"Pink Eye (Conjunctivitis)", {"red eye", "watery discharge", "irritation", "itchiness", "swelling"}, {8, 6, 5, 7, 6}},
{"Laryngitis", {"hoarseness", "sore throat", "dry cough", "voice loss", "throat irritation"}, {8, 6, 5, 9, 6}},
{"Mouth Ulcers", {"pain in mouth", "white spots", "difficulty eating", "burning", "bad taste"}, {7, 6, 6, 5, 4}}
};

int get_database_size() {
    return sizeof(database) / sizeof(Disease);
    }