"""Build and verify all62 frozen upstream BASE reference images."""
from pathlib import Path
import argparse,hashlib,subprocess,sys
p=argparse.ArgumentParser();p.add_argument('--build',action='store_true');a=p.parse_args()
root=Path(__file__).resolve().parent.parent
if a.build:subprocess.run([sys.executable,'build.py'],cwd=root,check=True)
rows=[line.split()for line in(root/'sha256sum.txt').read_text().splitlines()if line.strip()]
assert len(rows)==62 and len({q[1]for q in rows})==62
failed=[]
for expected,relative in rows:
    # Preserve upstream checksum values; its cutscene paths use build.wad/.
    if relative.startswith('build.wad/'):relative='build/wad/'+relative[len('build.wad/'):]
    path=root/relative
    actual=hashlib.sha256(path.read_bytes()).hexdigest()if path.is_file()else 'MISSING'
    if actual!=expected.lower():failed.append((relative,expected.lower(),actual))
for relative,expected,actual in failed:print(relative,'expected',expected,'actual',actual)
print(str(len(rows)-len(failed))+'/62 BASE reference images match; AI additions are not human reviewed.')
sys.exit(bool(failed))
