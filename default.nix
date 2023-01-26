let
  sources = import ./nix/sources.nix { };
  pkgs = import sources.nixpkgs {
    config = {
      permittedInsecurePackages = [
        # AFL depends on an old python version
        "python-2.7.18.6"
      ];
    };
  };
in

pkgs.stdenv.mkDerivation {
  name = "fuzzer-example";
  src = ./.;
  nativeBuildInputs = with pkgs; [ afl ];

  installPhase = ''
    mkdir -p $out
    find . -executable -type f -exec cp {} $out \;
  '';
}
