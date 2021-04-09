/**
    Project     : Composite Pattern Example

    Authors     : Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides
**/

///////////////////////////////////////////ICOMPONENT-INTERFACE///////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>

class IFileSystemComponent
{
    public:
        virtual ~IFileSystemComponent(){};
        virtual void list(int depth) = 0; //operation
        
        // Elimino las funciones add y remove. De esta manera la clase File no hereda estas funciones, que no necesita implementar.
        
//        virtual void add(IFileSystemComponent* component) = 0;
//        virtual void remove(IFileSystemComponent* component) = 0;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////COMPOSITE///////////////////////////////////////////////////////
class Folder : public IFileSystemComponent
{
    private:
        std::string m_nodeName;
        std::vector<IFileSystemComponent*> m_children;

    public:
        Folder(std::string nodeName)
        {
            m_nodeName = nodeName;
        }

        virtual ~Folder(){}
        
        void list(int depth)//operation
        {
            std::string newStr(depth, '-');
            std::cout << newStr << m_nodeName << " depth: " << depth << std::endl;
            for(IFileSystemComponent* currentChild : m_children)
            {
                if(currentChild != 0)
                {
                    currentChild->list(depth + 1);
                }
            }
        }

		// Implemento los métodos add y remove, siendo éstos únicos de la clase Folder.

        void add(IFileSystemComponent* component)
        {
            m_children.push_back(component);
        }

        void remove(IFileSystemComponent* component)
        {
            m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
        }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////LEAF////////////////////////////////////////////////////////
class File : public IFileSystemComponent
{
    private:
        std::string m_nodeName;
        
        // Al no tener hijos, no es necesario el vector.
//        std::vector<IFileSystemComponent*> m_children;

    public:
        File(std::string nodeName)
        {
            m_nodeName = nodeName;
        }

        virtual ~File(){}

        void list(int depth)//operation
        {
            std::string newStr(depth, '-');
            std::cout << newStr << m_nodeName << " depth: " << depth << std::endl;
            
            // Elimino el bucle for del list en File, de esta forma se puede listar un objeto File que esté dentro de una Folder
            // pero no se puede listar un File que esté dentro de otro File.
            
//            for(IFileSystemComponent* currentChild : m_children)
//            {
//                if(currentChild != 0)
//                {
//                    currentChild->list(depth + 1);
//                }
//            }
        }

			// Los métodos add y remove, al no ser necesarios para la clase File, se descartan. De esta manera no se puede añadir un objeto File dentro de otro del mismo tipo.

//        void add(IFileSystemComponent* component)
//        {
//            m_children.push_back(component);
//        }
//
//        void remove(IFileSystemComponent* component)
//        {
//            m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
//        }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////MAIN////////////////////////////////////////////////////////
int main()
{
    IFileSystemComponent* folder_01 = new Folder("folder_01");

    IFileSystemComponent* folder_02 = new Folder("folder_02");
    folder_01->add(folder_02);

    IFileSystemComponent* folder_03 = new Folder("folder_03");
    IFileSystemComponent* fileA = new File("file A");
    folder_03->add(fileA);
    folder_03->add(new File("file B"));
    folder_02->add(folder_03);

    
    folder_01->list(1);

    delete folder_03;
    delete folder_02;
    delete folder_01;
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
