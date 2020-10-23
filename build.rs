fn main() {
    println!("cargo:rustc-link-lib=wrapper");
    println!("cargo:rustc-link-search=src/c");
    println!("cargo:rustc-link-lib=dylib=stdc++")
}
