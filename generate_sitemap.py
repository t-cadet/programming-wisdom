import re
import json
import os
from datetime import datetime

BASE_URL = "https://t-cadet.github.io/programming-wisdom/"

def generate_sitemap():
    try:
        if not os.path.exists("index.html"):
            print("index.html not found.")
            return

        with open("index.html", "r", encoding="utf-8") as f:
            content = f.read()

        # Extract manifest between markers
        pattern = r'// <!-- MANIFEST_START -->.*?const manifest = (\[.*?\]);.*?// <!-- MANIFEST_END -->'
        match = re.search(pattern, content, re.DOTALL)
        
        if not match:
            print("Error: Could not find manifest between markers.")
            return

        manifest_json = match.group(1)
        
        # Strip trailing commas to make it valid JSON
        # Handles: , ] -> ]  and  , } -> }
        manifest_json = re.sub(r',\s*([\]\}])', r'\1', manifest_json)
        
        manifest = json.loads(manifest_json)

        sitemap_entries = []
        
        # Home page
        sitemap_entries.append(f"""  <url>
    <loc>{BASE_URL}</loc>
    <changefreq>daily</changefreq>
    <priority>1.0</priority>
  </url>""")

        for article in manifest:
            slug = article['slug']
            # Use 'updated' if available, otherwise 'date'
            date_str = article.get('updated') or article.get('date')
            
            # Ensure loc includes the hash for the SPA route
            loc = f"{BASE_URL}#{slug}"
            
            entry = f"""  <url>
    <loc>{loc}</loc>
    <lastmod>{date_str}</lastmod>
    <changefreq>monthly</changefreq>
    <priority>0.8</priority>
  </url>"""
            sitemap_entries.append(entry)

        entries_string = "\n".join(sitemap_entries)
        sitemap_xml = f"""<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
{entries_string}
</urlset>"""

        with open("sitemap.xml", "w", encoding="utf-8") as f:
            f.write(sitemap_xml)
        
        print(f"Generated sitemap.xml with {len(manifest) + 1} URLs.")

    except Exception as e:
        print(f"Error generating sitemap: {e}")

if __name__ == "__main__":
    generate_sitemap()
