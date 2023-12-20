#pragma once

void encode_image(const char* input_filename, const char* output_filename, const char xor_key) {
    FILE* input_file = fopen(input_filename, "rb");
    FILE* output_file = fopen(output_filename, "wb");

    if (input_file == NULL || output_file == NULL) {
        return;
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch ^ xor_key, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decode_image(const char* input_filename, const char* output_filename, const char xor_key) {
    FILE* input_file = fopen(input_filename, "rb");
    FILE* output_file = fopen(output_filename, "wb");

    if (input_file == NULL || output_file == NULL) {
        return;
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch ^ xor_key, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void HintMsgFunc() {
    const char* HintMsg = "Hint : Modulate parameters";
}