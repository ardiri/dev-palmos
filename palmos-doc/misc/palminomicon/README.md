# Palminomicon

**Historical Palm OS development and hardware reference archive (195-page scanned PDF).**

`folder-scan.pdf` is a collected set of late-1990s/early-2000s Palm OS development notes, archived web pages, technical articles, code listings, and hardware documentation. It is **not** a single official SDK manual or a modern, step-by-step tutorial.

## What's inside

- **Palm OS programming basics:** application startup and event loops, forms, resource definitions, memory chunks, `.PRC` applications, `.PDB` databases, bitmap drawing, and example C/resource code.
- **Development environment:** historical references to GCC cross-compilers, CodeWarrior, the Palm OS Emulator (POSE), ROM images, and debugging resources.
- **Devices and processors:** historical hardware comparison tables for Palm, Handspring, IBM WorkPad and related devices; Motorola MC68328 DragonBall and MC68EZ328 DragonBall EZ specifications and peripheral descriptions.
- **System internals:** interrupt and exception vectors, system traps, low-level API behavior, and historical Palm OS hacking techniques.
- **Database structures:** Palm database formats, headers, records and backup-related information.
- **Infrared communication:** substantial IrDA documentation, including protocol architecture and layers, IrCOMM/IrOBEX, device discovery, and Palm-specific sample code and discussions.
- **Security:** technical material concerning Palm OS password encoding and related utilities.
- **Graphics and LCD hardware:** bitmap data and compression, monochrome/grayscale/color display behavior, LCD controller programming, memory layouts, registers, timing, and Epson display-controller reference excerpts.

## Why keep it?

This archive is useful for understanding how early 68K Palm OS software and hardware worked, particularly when investigating undocumented behavior, emulator compatibility, infrared connectivity, framebuffer access, or legacy application code. It also preserves contemporary technical material that may be difficult to find online today.

## Reading notes

- The PDF contains **195 scanned pages** assembled from several sources. Formatting, page orientation and scan quality vary; some code pages are rotated.
- The text layer is imperfect, especially for code listings and tables. **Check the scanned page images** before copying code, register values or specifications.
- The material is historical: product availability, URLs, compatibility statements and security guidance reflect the period in which the originals were written.
- Some pages mention ROM downloads and licensing/export restrictions. **The PDF is documentation, not a bundle of ROM images or development binaries.** Consult applicable rights and licensing requirements for any external files.
- Source copyrights remain with their respective owners; inclusion here does not imply relicensing of the underlying documents.

## File

- [`folder-scan.pdf`](folder-scan.pdf) — the scanned reference collection.

## Scope

Primarily classic **Motorola 68K-era Palm OS**, especially Palm OS 3.x and contemporary devices. It should not be mistaken for comprehensive documentation of later ARM-based Palm OS systems.
