import os

def generate_raw_data():
    base_path = "."
    human_dir = os.path.join(base_path, "human")
    ai_dir = os.path.join(base_path, "ai")

    output = "    const rawData = [\n"

    for i in range(10):
        h_path = os.path.join(human_dir, f"{i}.c")
        a_path = os.path.join(ai_dir, f"{i}.c")

        # Human file
        with open(h_path, "r") as f:
            lines = f.readlines()
            h_source = lines[0].strip().replace("// ", "")
            h_code = "".join(lines[1:]).strip()

        # AI file
        with open(a_path, "r") as f:
            lines = f.readlines()
            a_source = lines[0].strip().replace("// ", "")
            a_code = "".join(lines[1:]).strip()

        # Escape backticks and ${ for JS template literals
        h_code = h_code.replace("`", "\`").replace("${", "\\${ ")
        a_code = a_code.replace("`", "\`").replace("${", "\\${ ")

        output += "      {\n"
        output += f"        h: {{ s: `{h_source}`, c: `{h_code}` }},\n"
        output += f"        a: {{ s: `{a_source}`, c: `{a_code}` }}\n"
        if i == 9:
            output += "      }\n"
        else:
            output += "      },\n"

    output += "    ];\n"
    print(output)

if __name__ == "__main__":
    generate_raw_data()
