#!/usr/bin/env python3
import os
import argparse

def collect_files(scan_dir, extensions, base):
    """
    递归遍历 scan_dir，收集扩展名在 extensions 列表中的文件，
    返回相对于 base 的文件路径列表，并将路径分隔符统一为正斜杠 (/)
    """
    files = []
    for dirpath, _, filenames in os.walk(scan_dir):
        for fname in filenames:
            if any(fname.lower().endswith(ext.lower()) for ext in extensions):
                full_path = os.path.join(dirpath, fname)
                # 相对于项目根目录（base）计算相对路径
                rel_path = os.path.relpath(full_path, base)
                # 将路径分隔符统一为 /
                rel_path = rel_path.replace(os.sep, '/')
                files.append(rel_path)
    return sorted(files)

def main():
    parser = argparse.ArgumentParser(
        description="扫描项目根目录下 src 文件夹中的源文件和头文件，并分别生成 cmake 变量输出"
    )
    parser.add_argument(
        "directory", nargs="?", default=".",
        help="项目根目录（默认为当前目录），脚本将从该目录下的 src 文件夹中扫描文件"
    )
    parser.add_argument(
        "--src-ext", nargs="+", default=[".cpp"],
        help="源文件的扩展名列表，默认为 .cpp"
    )
    parser.add_argument(
        "--hdr-ext", nargs="+", default=[".h"],
        help="头文件的扩展名列表，默认为 .h"
    )
    args = parser.parse_args()

    # 指定扫描项目根目录下的 src 文件夹
    src_folder = os.path.join(args.directory, "src")
    if not os.path.isdir(src_folder):
        print(f"Error: 目录 {src_folder} 不存在")
        return

    # 使用项目根目录作为 base，这样输出路径会保留 src 前缀
    src_files = collect_files(src_folder, args.src_ext, base=args.directory)
    hdr_files = collect_files(src_folder, args.hdr_ext, base=args.directory)

    # 输出 cmake 变量 srcs
    print("set(srcs")
    for f in src_files:
        print("    " + f)
    print(")")

    print()  # 空行分隔

    # 输出 cmake 变量 headers
    print("set(headers")
    for f in hdr_files:
        print("    " + f)
    print(")")

if __name__ == "__main__":
    main()
