# XScale Cross-Compiler Archive

This directory contains the historical XScale cross-compiler archive distributed as part of the ALP (Access Linux Platform) development resources. The original archive, `xscale-060924-2.tar.bz2`, is approximately 122 MB and exceeds GitHub's maximum individual file size of 100 MB. To preserve the original archive without requiring Git Large File Storage (LFS), it has been divided into smaller parts. These parts can be recombined to recreate the original archive without modification or loss of data.

## Archive Contents

The original archive is stored as:

```text
xscale-060924-2.tar.bz2.part-aaa
xscale-060924-2.tar.bz2.part-aab
xscale-060924-2.tar.bz2.part-aac
xscale-060924-2.tar.bz2.part-aad
```

Each part is a consecutive segment of the original binary archive.

## Reconstructing the Archive

On Linux or macOS, navigate to this directory and execute:

```bash
cat xscale-060924-2.tar.bz2.part-* > xscale-060924-2.tar.bz2
```

The resulting file is an exact binary reconstruction of the original archive.

To extract its contents:

```bash
tar -xjf xscale-060924-2.tar.bz2
```

Alternatively, the archive can be reconstructed and extracted directly without creating an intermediate file:

```bash
cat xscale-060924-2.tar.bz2.part-* | tar -xjvf -
```

## Verifying Integrity

The reconstructed archive should have an exact size of **128,394,430 bytes**.

Verify its size using:

```bash
wc -c < xscale-060924-2.tar.bz2
```

Optionally, verify that the archive is readable:

```bash
bzip2 -tv xscale-060924-2.tar.bz2
```

## Historical Preservation

These resources are retained for historical reference, research, and software preservation. The archive has been split solely to accommodate GitHub's file size restrictions. No modifications have been made to its contents. The tools are historical and may require legacy operating systems, libraries, or development environments to function correctly.
